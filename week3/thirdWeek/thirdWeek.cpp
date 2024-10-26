// thirdWeek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {

    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {

        if (r - l == 1)
        {
            if (nums[r] == target)
                return r;
            else if (nums[l] == target)
                return l;

            return -1;
        }

        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] <= nums[r]) {
            if (target <= nums[r] && target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        else if(nums[mid] >= nums[l]) {
            if (target >= nums[l] && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
    }

    if (l > r)
        return nums[r] == target ? r : -1;
    else
        return nums[l] == target ? l : -1;

}
int main()
{
    vector<int> n{5, 1, 2, 3, 4};
    cout << search(n,4);
}
