#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        unordered_map<int, int> weightsMap;
        for (int i = 0; i < nums.size(); i++)
            weightsMap[nums[i]] = i;

        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            
            int target = -nums[i];

            for (size_t j = i+1; j < nums.size(); j++)
            {
                if(weightsMap.count(target - nums[j]) && weightsMap[target - nums[j]] > j)
                    res.push_back({ nums[i], nums[j], target - nums[j] });
                j = weightsMap[nums[j]];
            }

            i = weightsMap[nums[i]];
        }

        return res;
    }
};