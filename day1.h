#pragma once
#include <map>
#include <string>
#include <vector>

class day1
{
private:
	inline static std::map<std::string, int> s_digits_ = {
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9},
	};

	[[nodiscard]] static int get_number(const std::string& text);
	[[nodiscard]] static int get_digit(const char& ch, const std::string& spelled, const bool& trim = false);

public:
	static void run_puzzle(const std::vector<std::string>& text_lines);
};

