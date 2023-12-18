#include "day2.h"
#include "common.h"

#include <iostream>
#include <map>
#include <ostream>

using namespace std;
typedef common c;

void day2::run_puzzle(const vector<string>& text_lines)
{
	int i = 0;
	int id_sum = 0;
	int power_sum = 0;

	for (const string& line : text_lines)
	{
		i++;
		auto values = get_values(line);
		if (is_possible(values)) id_sum += i;
		power_sum += get_power(values);
	}

	cout << "result 1: " << id_sum << endl;
	cout << "result 2: " << power_sum << endl;
}

bool day2::is_possible(const vector<string>& values)
{
	for (const auto& value : values)
	{
		for (auto& [color, upper_bound] : color_values_)
		{
			if (value.find(color) != string::npos 
				&& get_str_val(value) > upper_bound)
				return false;
		}
	}

	return true;
}

int day2::get_power(const vector<string>& values)
{
	std::map<std::string, int> color_minimums = {
		{"red", 0},
		{"green", 0},
		{"blue", 0}
	};

	for (const auto& value : values)
	{
		for (auto& [color, current_val] : color_minimums)
		{
			if (const int new_val = get_str_val(value); 
				value.find(color) != string::npos
				&& new_val > current_val)
				color_minimums[color] = new_val;
				
		}
	}

	return color_minimums["red"] * color_minimums["green"] * color_minimums["blue"];
}

vector<string> day2::get_values(const string& line)
{
	const string str = line.substr(line.find_first_of(':') + 2);
	vector<string> values;

	for (const auto& split : c::split(str, "; "))
	{
		for (const auto& value : c::split(split, ", "))
		{
			values.push_back(value);
		}
	}

	return values;
}
