#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

	ifstream file("./input.txt");
	string input;

	const clock_t start = clock();

	constexpr int lower_case_ascii_sub = 96;
	constexpr int upper_case_ascii_sub = 38;

	int total_priority = 0;

	while (getline(file, input))
	{
		const int line_length = input.size();
		vector<char> searched_chars;
		
		for (int i = 0; i < line_length / 2; ++i)
		{
			const char search = input.at(i);
			if (ranges::find(searched_chars, search) != searched_chars.end())
			{
				continue;
			}

			searched_chars.push_back(search);
			if (input.find(search, line_length / 2) != string::npos)
			{
				total_priority += search > 96 ? search - lower_case_ascii_sub : search - upper_case_ascii_sub;
			}
		}
	}

	const time_t end = clock();

	cout << "Total priority: " << total_priority << endl;
	const double time_taken = (static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
	cout << "Time taken: " << time_taken << "ms" << endl;
}
