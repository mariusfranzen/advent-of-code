#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const clock_t start = clock();

	ifstream file("./input.txt");
	string input;
	int score1 = 0;
	int score2 = 0;
	
	while (getline(file, input))
	{
		if (input.empty())
		{
			break;
		}

		score1 += input[2] - 87;
		const int result = (input[2] - input[0] - 23 + 3) % 3;

		if (result == 1)
		{
			score1 += 6;
		}
		else if (result == 0)
		{
			score1 += 3;
		}

		int score = (input[0] + input[2] - 65 - 88) % 3;
		if (score == 0)
		{
			score = 3;
		}

		score2 += score + (input[2] - 88) * 3;
	}

	const clock_t end = clock();

	cout << "Total score 1: " << score1 << endl;
	cout << "Total score 2: " << score2 << endl;

	const double time_taken = (static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
	cout << "Time taken: " << time_taken << "ms" << endl;
}
