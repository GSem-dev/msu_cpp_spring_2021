#include "sort.h"
#include <cassert>

void test_1()
{
	size_t Size = 8192000;
    std::ofstream ofile;
    uint64_t t;
    uint64_t t1;
    std::ifstream file;
    ofile.open("bin.dat", std::ios::binary);
    if (!ofile.is_open())
    {
        std::cout << "Error open file\n";
    }

    for (uint64_t i = 0; i < Size; i++)
    {
        uint64_t r = rand();
        ofile.write((char*)&r, sizeof(uint64_t));
    }
    ofile.close();

    try
    {
        star_sort("bin.dat", "out.dat", 8388608);

        file.open("out.dat", std::ios::binary);
        for (uint64_t i = 0; i < Size / 2; ++i)
        {
            file.read((char*)&t, sizeof(uint64_t));
            file.read((char*)&t1, sizeof(uint64_t));
            //cout << t << ' ' << t1 << endl;
            assert(t <= t1);
        }
        file.close();
        std::cout << "Test 1 is Ok\n";
    }
    catch (const std::exception& err)
    {
        std::cout << err.what();
    }
    catch (...)
    {
        std::cout << "Error\n";
    }

    std::remove("bin.dat");
    std::remove("out.dat");
    std::remove("tmp.bin");

}

void test_2()
{
    int64_t Size = 10000000;
    std::ofstream ofile;
    uint64_t t;
    uint64_t t1;
    std::ifstream file;
    ofile.open("bin.dat", std::ios::binary);
    if (!ofile.is_open())
    {
        std::cout << "Error open file\n";
    }

    for (int64_t i = -Size/2; i < Size/2; i++)
    {
        uint64_t r = i*i;//все квадраты помещаются в int64_t
        ofile.write((char*)&r, sizeof(uint64_t));
    }
    ofile.close();

    try
    {
        star_sort("bin.dat", "out.dat", 8388608);

        file.open("out.dat", std::ios::binary);
        for (uint64_t i = 0; i < Size / 2; ++i)
        {
            file.read((char*)&t, sizeof(uint64_t));
            file.read((char*)&t1, sizeof(uint64_t));
            //cout << t << ' ' << t1 << endl;
            assert(t <= t1);
        }
        file.close();
        std::cout << "Test 2 is Ok\n";
    }
    catch (const std::exception& err)
    {
        std::cout << err.what();
    }
    catch (...)
    {
        std::cout << "Error\n";
    }

    std::remove("bin.dat");
    std::remove("out.dat");
    std::remove("tmp.bin");

}

int main()
{
    test_1();
    test_2();
}
