#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {

            int mid = l + (r - l) / 2;

            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];

            bool isOnTheFirst = nums[mid] == nums[mid + 1];

            if (isOnTheFirst && (r - mid + 1) % 2 == 0)
                r = mid - 1;
            else if (isOnTheFirst)
                l = mid + 2;
            else if ((r - mid + 1) % 2 == 1)
                r = mid - 2;
            else
                l = mid + 1;
        }

        return nums[l];
    }
};