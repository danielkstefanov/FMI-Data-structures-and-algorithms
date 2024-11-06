#include <iostream>
#include <queue>
using namespace std;

bool areValidCoordinates(int rows, int cols, int x, int y)
{
	return x >= 0 && x < rows && y >= 0 && y < cols;
}

void spreadSpoiling(int rows, int cols, bool** matrix, queue<pair<int, int>>& lastSpoiledApples)
{
	int spoiledApplesCount = lastSpoiledApples.size();

	for (size_t i = 0; i < spoiledApplesCount; i++)
	{
		pair<int, int> appleToSpread = lastSpoiledApples.front();
		lastSpoiledApples.pop();

		pair<int, int> neigbourPoints[4] = { {appleToSpread.first + 1, appleToSpread.second},
											 {appleToSpread.first - 1, appleToSpread.second},
											 {appleToSpread.first, appleToSpread.second + 1},
											 {appleToSpread.first, appleToSpread.second - 1} };

		for (size_t j = 0; j < 4; j++)
		{
			if (areValidCoordinates(rows, cols, neigbourPoints[j].first, neigbourPoints[j].second)
				&& !matrix[neigbourPoints[j].first][neigbourPoints[j].second])
			{
				matrix[neigbourPoints[j].first][neigbourPoints[j].second] = true;
				lastSpoiledApples.push({ neigbourPoints[j].first, neigbourPoints[j].second });
			}
		}

	}


}

void spoiledApplesSpreader()
{
	int N, M, T;
	cin >> N >> M >> T;

	bool** matrix = new bool* [N];

	for (size_t i = 0; i < N; i++)
		matrix[i] = new bool[M] {false};

	int firstBadAppleRow, firstBadAppleCol;
	cin >> firstBadAppleRow >> firstBadAppleCol;
	firstBadAppleRow = N - firstBadAppleRow;
	firstBadAppleCol--;
	matrix[firstBadAppleRow][firstBadAppleCol] = true;

	queue<pair<int, int>> lastSpoiledApples;
	lastSpoiledApples.push({ firstBadAppleRow,firstBadAppleCol });
	int spoiledCount = 1;

	int secondBadAppleRow, secondBadAppleCol;

	while (cin >> secondBadAppleRow >> secondBadAppleCol)
	{
		secondBadAppleRow = N - secondBadAppleRow;
		secondBadAppleCol--;

		matrix[secondBadAppleRow][secondBadAppleCol] = true;
		lastSpoiledApples.push({ secondBadAppleRow,secondBadAppleCol });
		spoiledCount++;
		break;
	}

	for (size_t i = 0; i < T; i++)
	{
		spreadSpoiling(N, M, matrix, lastSpoiledApples);
		spoiledCount += lastSpoiledApples.size();
	}

	std::cout << (N * M) - spoiledCount;
}