#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = lower_bound(nums.begin(), nums.end(), target);
        if (first == nums.end() || *first > target)
            return { -1, -1 };

        auto last = upper_bound(nums.begin(), nums.end(), target);
        return { (int)(first - nums.begin()), (int)(last - nums.begin() - 1) };
    }
};