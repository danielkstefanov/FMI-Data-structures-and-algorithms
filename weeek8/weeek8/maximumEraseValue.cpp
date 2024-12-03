#include <set>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    int start = 0;
    int end = 0;
    int maxSum = nums[start];
    int currentSum = nums[start];

    unordered_set<int> included;
    included.insert(nums[start]);

    while (end < nums.size() - 1) {

        end++;
        while (included.count(nums[end])) {
            currentSum -= nums[start];
            included.erase(nums[start]);
            start++;
        }
        currentSum += nums[end];
        included.insert(nums[end]);

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}