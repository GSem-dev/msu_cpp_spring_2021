#pragma once
#include <future>
#include <mutex>
#include <thread>
#include <queue>
#include <functional>
#include <condition_variable>
#include <vector>

using Function = std::function<void()>;

class ThreadPool
{
    bool work;
    size_t Size;
    std::queue<Function> queue;
    std::vector<std::thread> pool;
    std::mutex mutex;
    std::condition_variable getReady;
public:
    explicit ThreadPool(size_t poolSize) :work(true),Size(poolSize)
    {
        for (size_t i = 0; i < Size; i++)
        {
            pool.emplace_back([this]()
                {
                    while (work)
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        if (!queue.empty())
                        {
                            Function f = std::move(queue.front());
                            queue.pop();
                            lock.unlock();
                            f();
                        }
                        else
                        {
                            getReady.wait(lock);
                        }
                    }
                }
            );
        }
    }

    template <class Func, class... Args>
    auto exec(Func func, Args... args)->std::future<decltype(func(args...))>
    {
        auto p = std::make_shared<std::packaged_task<decltype(func(args...))()> >(
            std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
        {
            std::lock_guard<std::mutex> lock(mutex);

            queue.emplace([p]()
                {
                    (*p)();
                });
        }
        getReady.notify_one();
        return p -> get_future(); 
    }

    ~ThreadPool()
    {
        work = false;
        getReady.notify_all();
        size_t pool_len = pool.size();
        for (size_t i = 0; i < pool_len; i++)
        {
            pool[i].join();
        }
        pool.clear();
      }
};
