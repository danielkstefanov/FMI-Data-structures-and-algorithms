#include <vector>

using namespace std;

class Solution {
public:
	int minCostClimbingStairsUpToN(vector<int>& dp, vector<int>& cost, int n) {
		if (dp.size() > n)
			return dp[n];

		int answer = min(minCostClimbingStairsUpToN(dp, cost, n - 1), minCostClimbingStairsUpToN(dp, cost, n - 2)) + cost[n];
		dp.push_back(answer);
		return answer;
	}
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> dp{cost[0], cost[1]};
		minCostClimbingStairsUpToN(dp, cost, cost.size() - 1);
		return min(dp[dp.size() - 1], dp[dp.size() - 2]);
	}
};