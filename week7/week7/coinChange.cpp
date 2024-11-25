#include <vector>

using namespace std;


int coinChange(vector<int>& coins, int amount) {

    vector<int> dp {0};

    for (int i = 1; i <= amount; i++) {
        int currentCoinsCount = INT_MAX;

        for (int j = 0; j < coins.size(); j++) {

            if (i - coins[j] < 0)
                continue;

            if (dp[i - coins[j]] + 1 < currentCoinsCount && dp[i - coins[j]] != -1) {
                currentCoinsCount = dp[i - coins[j]] + 1;
            }

        }

        if (currentCoinsCount == INT_MAX)
            currentCoinsCount = -1;

        dp.push_back(currentCoinsCount);
    }

    return dp[amount];
}

int main() 
{
    vector<int >coins{2};
    coinChange(coins, 3);
}