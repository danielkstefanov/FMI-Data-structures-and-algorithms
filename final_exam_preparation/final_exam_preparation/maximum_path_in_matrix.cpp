#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct PairHash {
	template <typename T1, typename T2>
	size_t operator()(const std::pair<T1, T2>& p) const {
		auto hash1 = std::hash<T1>{}(p.first);
		auto hash2 = std::hash<T2>{}(p.second); 
		
		return hash1 ^ (hash2 << 1);
	}
};

void maximum_path_in_matrix()
{
	int size, special_positions_count, x, y;
	cin >> size;

	vector<vector<int>> matrix(size, vector<int>(size, 0));

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
			cin >> matrix[i][j];
	}

	cin >> special_positions_count;
	unordered_set<pair<int, int>, PairHash> special_positions;

	for (size_t i = 0; i < special_positions_count; i++)
	{
		cin >> x >> y;
		special_positions.insert({ x,y });
	}

	vector<vector<long long>> dp(size, vector<long long>(size, 0));
	dp[0][0] = matrix[0][0];

	for (size_t i = 1; i < size; i++)
		dp[0][i] = matrix[0][i] + dp[0][i-1];
	
	for (size_t i = 1; i < size; i++)
		dp[i][0] = matrix[i][0] + dp[i-1][0];

	for (size_t i = 1; i < size; i++)
	{
		for (size_t j = 1; j < size; j++)
		{
			long long prev_cell_max = max(dp[i-1][j], dp[i][j - 1]);
			if (special_positions.count({ i,j }))
				prev_cell_max = max(prev_cell_max, dp[i - 1][j - 1]);

			dp[i][j] = prev_cell_max + matrix[i][j];
		}
	}

	cout << dp[size - 1][size - 1];
}