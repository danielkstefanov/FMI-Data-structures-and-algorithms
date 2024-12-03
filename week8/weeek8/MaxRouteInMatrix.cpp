#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>


using namespace std;

vector<vector<int>> dp;

struct PairHash {
	template <typename T1, typename T2>
	std::size_t operator()(const std::pair<T1, T2>& pair) const {
		auto hash1 = std::hash<T1>{}(pair.first);
		auto hash2 = std::hash<T2>{}(pair.second);
		return hash1 ^ (hash2 << 1);
	}
};

int bestPath(unordered_set<pair<int, int>,PairHash>& diagonals,vector<vector<int>>& matrix, int x, int y)
{
	if (x < 0 || y < 0) 
		return INT_MIN;

	if (x == 0 && y == 0)
		return matrix[0][0];

	if (dp[x][y] != INT_MIN)
		return dp[x][y];

	int currentBestPath = max(bestPath(diagonals, matrix,x,y-1), bestPath(diagonals, matrix, x - 1, y));

	if (diagonals.count({ x,y }))
		currentBestPath = max(currentBestPath, bestPath(diagonals, matrix, x - 1, y - 1));

	currentBestPath += matrix[x][y];

	dp[x][y] = currentBestPath;

	return currentBestPath;
}


int main()
{
	int N, diagonalsCount;
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N, -1));
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
			cin >> matrix[i][j];
	}

	cin >> diagonalsCount;
	unordered_set<pair<int, int>, PairHash> diagonals;

	for (size_t i = 0; i < diagonalsCount; i++)
	{
		int x, y;
		cin >> x >> y;
		diagonals.insert({ x,y });
	}

	dp = vector<vector<int>>(N, vector<int>(N, INT_MIN));

	cout << bestPath(diagonals,matrix, N - 1,N-1);
}