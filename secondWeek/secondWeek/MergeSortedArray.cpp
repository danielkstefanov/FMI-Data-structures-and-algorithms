#include <vector>

using namespace std;

class Solution {
public:
    void shiftByIndex(vector<int>& arr, int size, int startingIndex) {
        for (int i = size - 1; i > startingIndex; i--)
            arr[i] = arr[i - 1];
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int left = 0;
        int right = 0;

        for (int i = 0; i < m + n; i++) {
            if (right == n)
                return;
            if (left - right == m)
                break;
            if (nums1[left] <= nums2[right]) {
                left++;
            }
            else {
                shiftByIndex(nums1, m + n, left);
                nums1[left++] = nums2[right++];
            }
        }

        for (int i = left; i < m + n; i++)
            nums1[i] = nums2[right++];
    }
};
