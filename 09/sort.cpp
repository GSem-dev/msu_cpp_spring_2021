#include "sort.h"

size_t mini(const std::vector< MinEl>& vec)
{
	if (vec.empty())
	{
		throw std::runtime_error("ERROR: vector is empty");
	}
	size_t min = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i].get_val() < vec[min].get_val())
		{
			min = i;
		}
	}
	return min;
}

void sorted(std::ifstream& input, std::ofstream& out, size_t buf_size, std::mutex& mut_1, std::mutex& mut_2)
{

	std::unique_ptr<uint64_t[]> a(new uint64_t[buf_size / sizeof(uint64_t)]);
	while (true)
	{
		{
			std::unique_lock<std::mutex> lock{ mut_1 };
			input.read((char*)a.get(), buf_size);
		}
		size_t a_counts = input.gcount();
		if (a_counts == 0)
			break;
		std::sort(a.get(), a.get() + a_counts / sizeof(uint64_t));
		{
			std::unique_lock<std::mutex> lock{ mut_2 };
			out.write((char*)&a_counts, sizeof(size_t));
			out.write((char*)a.get(), a_counts);
		}
	}
}

void multi_merge(const std::string& input_path, const std::string& output_path)
{
	std::ifstream new_tmp(input_path, std::ios::binary);
	std::ofstream output(output_path, std::ios::binary);
	std::vector<MinEl> vec;
	while (true)
	{
		uint64_t value;
		size_t bin_size;
		size_t bias_f;
		size_t bias_s;
		if (!new_tmp.read((char*)&bin_size, sizeof(size_t)))
		{
			break;
		}
		new_tmp.read((char*)&value, sizeof(uint64_t));
		bias_f = static_cast<uint64_t>(new_tmp.tellg());
		bias_s = bias_f + bin_size - sizeof(uint64_t);
		MinEl elem(value, bias_f, bias_s);
		vec.push_back(elem);
		new_tmp.seekg(bin_size - sizeof(uint64_t), std::ios::cur);
	}
	new_tmp.clear();
	while (true)
	{
		if (vec.empty())
		{
			break;
		}
		if (vec.size() == 1)
		{
			MinEl min = vec[0];
			uint64_t das = min.get_val();
			output.write((char*)&das, sizeof(uint64_t));
			uint64_t i = 0;
			while (true)
			{
				if ((min.get_curr() + i * sizeof(uint64_t)) == min.get_ex())
				{
					break;
				}
				new_tmp.seekg(min.get_curr() + i * sizeof(uint64_t));
				new_tmp.read((char*)&das, sizeof(uint64_t));
				output.write((char*)&das, sizeof(uint64_t));
				i++;
			}
			break;
		}
		size_t min_bias = mini(vec);
		MinEl min = vec[min_bias];
		vec.erase(vec.begin() + min_bias);
		uint64_t das = min.get_val();
		output.write((char*)&das, sizeof(uint64_t));
		if (min.empty())
		{
			continue;
		}
		new_tmp.seekg(min.get_curr());
		uint64_t new_val;
		new_tmp.read((char*)&new_val, sizeof(uint64_t));
		MinEl elem(new_val, sizeof(uint64_t) + min.get_curr(), min.get_ex());
		vec.push_back(elem);
	}
	new_tmp.close();
	output.close();
}

void star_sort(const std::string& input_path, const std::string& output_path, size_t buf_size)
{
	std::ifstream input(input_path, std::ios::binary);
	std::ofstream tmp("tmp.bin", std::ios::binary);
	std::mutex mutex_1;
	std::mutex mutex_2;
	auto bind_sort = std::bind(sorted, std::ref(input), std::ref(tmp), buf_size, std::ref(mutex_1), std::ref(mutex_2));
	std::thread thr1(bind_sort);
	std::thread thr2(bind_sort);
	thr1.join();
	thr2.join();
	tmp.close();
	multi_merge("tmp.bin", output_path);
}
