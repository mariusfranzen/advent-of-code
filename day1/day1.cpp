#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "StringUtils.h"
#include "Sorting.h"
#include <vector>

using namespace std;
using namespace CppUtils;

int elves = 0;

int main()
{
	const clock_t start = clock();

	ifstream file("./input.txt");

	string input;
	int current_calories = 0;
	vector<int> calories;
	while (getline(file, input))
	{
		if (StringUtils::IsNumber(input))
		{
			current_calories += stoi(input);
		}
		else
		{
			calories.push_back(current_calories);
			current_calories = 0;
		}
	}

	const int size = calories.size();
	const auto calories_array = new int[size];

	std::copy(calories.begin(), calories.end(), calories_array);

	Sorting::QuickSort(calories_array, 0, size - 1);
	Sorting::Reverse(calories_array, size);

	const int highest_calorie_count = calories_array[0];
	const int top_3_elves = calories_array[0] + calories_array[1] + calories_array[2];

	file.close();

	const clock_t end = clock();

	cout << "Highest calorie count: " << highest_calorie_count << endl;
	cout << "The 3 elves with the most calories have a combined calorie count of: " << top_3_elves << endl;

	const double time_taken = (static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
	cout << "Time taken: " << time_taken << "ms" << endl;
}
