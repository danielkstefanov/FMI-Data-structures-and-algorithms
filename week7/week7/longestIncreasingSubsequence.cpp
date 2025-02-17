#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;

            for (int j = 0; j < i;j++)
            {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};