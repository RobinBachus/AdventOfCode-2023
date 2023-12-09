#include "day1.h"

#include <iostream>

int day1::get_number(const std::string& text)
{
	int first_digit = 0;
	std::string spelled;

	for (const auto ch : text)
	{
		spelled += ch;
		first_digit = get_digit(ch, spelled, true) * 10;
		if (first_digit != 0) break;
	}

	spelled = "";

	auto r_text = text;
	std::reverse(r_text.begin(), r_text.end());
	int second_digit = 0;

	for (const char ch : r_text)
	{
		spelled.insert(0, 1, ch);
		second_digit = get_digit(ch, spelled);
		if (second_digit != 0) break;
	}

	std::cout << first_digit + second_digit << std::endl;

	return first_digit + second_digit;
}

int day1::get_digit(const char& ch, const std::string& spelled, const bool& trim)
{
	if (spelled.empty()) return 0;

	if (ch >= 49 && ch <= 57)
		return ch - 48;

	for (const auto& [str, number] : s_digits_)
	{
		if (spelled.find(str)) continue;
		return number;
	}

	if (!trim || spelled.length() < 3) return 0;

	for (size_t i = 1; i <= spelled.length() - 3; i++)
	{
		for (const auto& [str, number] : s_digits_)
		{
			if (std::string sub = spelled.substr(i, spelled.length()); sub.find(str)) continue;
			return number;
		}
	}

	return 0;
}

void day1::run_puzzle(const std::vector<std::string>& text_lines)
{
	int result = 0;

	for (const auto& line : text_lines)
		result += get_number(line);

	std::cout << "Result:" << result << std::endl;
}
