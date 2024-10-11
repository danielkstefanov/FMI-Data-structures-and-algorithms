#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {

        if (start > end)
        {
            return;
        }

        for (int i = 0; i <= (end - start) / 2; i++) {
            swap(nums[start + i], nums[end - i]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();

        if (k == 0) {
            return;
        }

        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - k - 1);
        reverse(nums, 0, nums.size() - 1);
    }
};