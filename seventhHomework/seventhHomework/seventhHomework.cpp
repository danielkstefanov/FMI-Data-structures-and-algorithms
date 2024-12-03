#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int longestCommonSubstring(const string& first, const string& second)
{
	vector<vector<int>> dp(second.length(), vector<int>(first.length(), 0));
	int max_length = 0;

	for (size_t i = 0; i < first.length(); i++)
	{
		if (first[i] == second[0])
		{
			dp[0][i] = 1;
			max_length = 1;
		}
	}

	for (size_t i = 0; i < second.length(); i++)
	{
		if (second[i] == first[0])
		{
			dp[i][0] = 1;
			max_length = 1;
		}
	}

	for (size_t i = 1; i < first.length(); i++)
	{
		for (size_t j = 1; j < second.length(); j++)
		{
			if (first[i] == second[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				max_length = max(max_length, dp[i][j]);
			}
		}
	}

	return max_length;
}

int main()
{
	string first;
	cin >> first;

	string second;
	cin >> second;

	cout << longestCommonSubstring(first, second);
}