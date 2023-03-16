#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "StringUtils.h"

using namespace std;
using namespace CppUtils;

int elves = 0;

int main()
{
	clock_t start, end;
	start = clock();

	ifstream file("./input.txt");

	string input;
	int highestCalorieCount = 0;
	int currentCalorieCount = 0;
	while (getline(file, input))
	{
		if (StringUtils::IsNumber(input))
		{
			currentCalorieCount += stoi(input);
		}
		else if (currentCalorieCount > highestCalorieCount)
		{
			highestCalorieCount = currentCalorieCount;
			currentCalorieCount = 0;
		}
		else
		{
			currentCalorieCount = 0;
		}
	}

	file.close();

	end = clock();

	cout << "Highest calorie count: " << highestCalorieCount << endl;

	double timeTaken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
	cout << "Time taken: " << timeTaken << "ms" << endl;
}

// Part 1 time: 8ms
