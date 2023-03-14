#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int elves = 0;

bool isNumber(const string s) 
{
	std::string::const_iterator it = s.begin();

	while (it != s.end() && std::isdigit(*it))
	{
		++it;
	}

	return !s.empty() && it == s.end();
}

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
		if (isNumber(input))
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
