#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int totalCount = 0;
        int currentSum = 0;

        for (int el : nums) {
            currentSum += el;

            totalCount += map[currentSum - k];
            map[currentSum] += 1;
        }

        return totalCount;
    }
};