#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

// Searching algorithms 
// 
// Linear seacrh - O(n) check every element
// 
// Binary search - work with sorted data. Check in the middle. If the element you are searching
// for is smaller than look only on the elements on the left. If not look only on the elements
// on the right. This way we achieve O(logn)
// 
// Ternary search - the same idea with binary search but we remove 2/3 of the elements 
// and not 1/2 of them. This doesnt mean that this algorithm is better because we have
// 2 comparisons in order to remove 2/3 of the elements. But in the binary search we 
// remove 1/2 of the elements with only one comparison.
// 
// Step search - O(sqrt(n)) useful when you have some logic like a harddisc and in order 
// to read again the data you have to return from the begging. The step is sqrt(n) long.
// 

using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // !!!
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}


int binarySearchRecursive(const vector<int>& arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearchRecursive(arr, l, mid - 1, x);
        return binarySearchRecursive(arr, mid + 1, r, x);
    }
    return -1;
}


int ternarySearch(const vector<int>& arr, int l, int r, int x) {
    while (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == x)
            return mid1;
        if (arr[mid2] == x)
            return mid2;
        if (x < arr[mid1]) {
            r = mid1 - 1;
        }
        else if (x > arr[mid2]) {
            l = mid2 + 1;
        }
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}
