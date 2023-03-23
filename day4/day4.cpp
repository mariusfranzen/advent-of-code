#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "StringUtils.h"

using namespace std;
using namespace CppUtils;

void MySolution1()
{
	ifstream file("./input.txt");
	string line;

	const clock_t start = clock();

	int full_duplicate_count = 0;

	while (getline(file, line))
	{
		vector<string> elves = StringUtils::SplitString(line, ",");
		vector<string> sections;

		for (auto& elf : elves)
		{
			vector<string> new_sections = StringUtils::SplitString(elf, "-");
			for (const auto& new_section : new_sections)
			{
				sections.push_back(new_section);
			}
		}

		const bool first_includes_second = stoi(sections.at(0)) <= stoi(sections.at(2)) && stoi(sections.at(1)) >= stoi(sections.at(3));
		const bool second_includes_first = stoi(sections.at(2)) <= stoi(sections.at(0)) && stoi(sections.at(3)) >= stoi(sections.at(1));

		if (first_includes_second || second_includes_first)
		{
			full_duplicate_count++;
		}
	}

	const time_t end = clock();

	cout << "Duplicates: " << full_duplicate_count << endl << endl;
	const double time_taken = (static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
	cout << "Time taken: " << time_taken << "ms" << endl;
}

void MySolution2()
{
	ifstream file("./input.txt");
	string line;

	const clock_t start = clock();

	int full_duplicate_count = 0;

	while (getline(file, line))
	{
		int interval1[2], interval2[2];

		interval1[0] = stoi(line.substr(0, line.find_first_of('-')));
		interval1[1] = stoi(line.substr(line.find_first_of('-') + 1, line.find_first_of(',')));

		interval2[0] = stoi(line.substr(line.find_first_of(',') + 1, line.find_last_of('-')));
		interval2[1] = stoi(line.substr(line.find_last_of('-') + 1, line.length()));

		const bool first_includes_second = interval1[0] <= interval2[0] && interval1[1] >= interval2[1];
 		const bool second_includes_first = interval2[0] <= interval1[0] && interval2[1] >= interval1[1];


		//const bool first_includes_second = stoi(sections.at(0)) <= stoi(sections.at(2)) && stoi(sections.at(1)) >= stoi(sections.at(3));
		//const bool second_includes_first = stoi(sections.at(2)) <= stoi(sections.at(0)) && stoi(sections.at(3)) >= stoi(sections.at(1));

		if (first_includes_second || second_includes_first)
		{
			full_duplicate_count++;
		}
	}

	const time_t end = clock();

	cout << "Duplicates: " << full_duplicate_count << endl << endl;
	const double time_taken = (static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
	cout << "Time taken: " << time_taken << "ms" << endl;
}

void RedditInspired1()
{
	ifstream file("./input.txt");
	string line;

	const clock_t start = clock();

	int full_duplicate_count = 0;

	while (getline(file, line))
	{
		int interval1[2], interval2[2];
		int early_start_interval[2], late_start_interval[2];

		interval1[0] = stoi(line.substr(0, line.find_first_of('-')));
		interval1[1] = stoi(line.substr(line.find_first_of('-') + 1, line.find_first_of(',')));

		interval2[0] = stoi(line.substr(line.find_first_of(',') + 1, line.find_last_of('-')));
		interval2[1] = stoi(line.substr(line.find_last_of('-') + 1, line.length()));
		
		if (interval1[0] <= interval2[0])
		{
			copy_n(interval1, 2, early_start_interval);
			copy_n(interval2, 2, late_start_interval);
		}
		else
		{
			copy_n(interval2, 2, early_start_interval);
			copy_n(interval1, 2, late_start_interval);
		}

		if (early_start_interval[0] == late_start_interval[0] || early_start_interval[1] >= late_start_interval[1])
		{
			full_duplicate_count++;
		}
	}

	const time_t end = clock();

	cout << "Duplicates: " << full_duplicate_count << endl << endl;
	const double time_taken = (static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
	cout << "Time taken: " << time_taken << "ms" << endl;
}

int main()
{
	cout << "My first solution: " << endl;
	MySolution1();
	cout << endl << "--------------------" << endl << "Reddit inspired solution: " << endl;
	RedditInspired1();
	cout << endl << "--------------------" << endl << "My improved solution solution: " << endl;
	MySolution2();
}
