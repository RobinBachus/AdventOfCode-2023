#pragma once

#include <map>
#include <optional>
#include <string>
#include <vector>

#include "common.h"

class day2
{
public:
	static void run_puzzle(const std::vector<std::string>& text_lines);

private:
	inline static std::map<std::string, int> color_values_ = {
		{"red", 12},
		{"green", 13},
		{"blue", 14}
	};

	static int get_str_val(const std::string& str)
	{
		return std::stoi(common::split(str, " ")[0]);
	}

	static bool is_possible(const std::vector<std::string>& values);
	static int get_power(const std::vector<std::string>& values);

	static std::vector<std::string> get_values(const std::string& line);
};

