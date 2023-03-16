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
	clock_t start, end;
	start = clock();

	ifstream file("./input.txt");

	string input;
	int currentCalories = 0;
	vector<int> calories;
	while (getline(file, input))
	{
		if (StringUtils::IsNumber(input))
		{
			currentCalories += stoi(input);
		}
		else
		{
			calories.push_back(currentCalories);
			currentCalories = 0;
		}
	}

	int size = calories.size();
	int* caloriesArray;
	caloriesArray = new int[size];

	std::copy(calories.begin(), calories.end(), caloriesArray);

	Sorting::QuickSort(caloriesArray, 0, size - 1);
	Sorting::Reverse(caloriesArray, size);
	
	int highestCalorieCount = caloriesArray[0];
	int top3Elves = caloriesArray[0] + caloriesArray[1] + caloriesArray[2];

	file.close();

	end = clock();

	cout << "Highest calorie count: " << highestCalorieCount << endl;
	cout << "The 3 elves with the most calories have a combined calorie count of: " << top3Elves << endl;

	double timeTaken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
	cout << "Time taken: " << timeTaken << "ms" << endl;
}
