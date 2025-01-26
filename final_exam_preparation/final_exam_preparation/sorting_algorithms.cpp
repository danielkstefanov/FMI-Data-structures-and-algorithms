#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

// Sorting algorithms
// stability, in-place, adaptivity, locality
//
// 
// Slow sorting algorithms - O(n^2)
// 
// Bubble sort - on each step takes the biggest element to the end (by swapping)
// Insertions sort - assume that the last k elements are sorted. You take the first element and progressively insert it in the right position
// Selection sort - select the smallest element and put it first. Then get the second smallest and put it second. etc.
// 
// Fast sorting algorithms
// 
// Merge sort - O(n*logn) by time in every case   O(n) space complexity
// - recursive algorithm. Sort the first half, then sort the second half, then merge them.
//
// Quick sort - O(n*logn) in average case and O(n*logn) in worst case time complexity. O(logn) space complexity because there is a inplace implementation, but still its logn because of the recursion
// - partition the array by the key. On each step we are sure that
//		1. The key is on its spot.
//		2. All the elements to the left are smaller.
//		3. All the elements to the right are bigger.
//
//	
// Count sort - O(n+k) time complexity and O(n+k) space complexity
// - its possible to create an sorting algorithm with smaller than n*logn complexity only if we have some contraints.
// - in this case we know that the elements in this array are in some range
// - we count occurences of the numbers and then create the result array.
//
//


using namespace std;

void bubble_sort_slow(vector<int>& arr)
{
	int size = arr.size();

	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}


void bubble_sort_fast(vector<int>& arr)
{
	int size = arr.size();
	int last_swap_index = size - 1;

	for (size_t i = 0; i < size - 1; i++)
	{
		int current_last_swap = 0;
		for (size_t j = 0; j < last_swap_index; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				current_last_swap = j;
			}
		}

		if (current_last_swap == 0)
			return;

		last_swap_index = current_last_swap;
	}
}


void selection_sort(vector<int>& arr)
{
	size_t size = arr.size();

	for (size_t i = 0; i < size; i++)
	{
		int min_index = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
		}

		if (min_index != i)
			swap(arr[i], arr[min_index]);
	}
}

void insertion_sort(vector<int>& arr)
{
	int size = arr.size();

	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] == key;
	}
}

void merge(vector<int>& arr, int start, int mid, int end, vector<int>& buffer)
{
	int left_start = start;
	int right_start = mid;
	int index = 0;

	while (left_start < mid && right_start < end)
	{
		if (arr[left_start] < arr[right_start])
			buffer[index++] = arr[left_start++];
		else
			buffer[index++] = arr[right_start++];
	}

	while (left_start < mid)
		buffer[index++] = arr[left_start++];

	while (right_start < end)
		buffer[index++] = arr[right_start++];

	for (size_t i = 0; i < index; i++)
		arr[i+start] = buffer[i];
}

void _merge_sort(vector<int>& arr, int l, int r, vector<int>& buffer)
{
	if (r - l <= 1)
		return;
	
	size_t mid = l + (r - l) / 2;

	_merge_sort(arr, l, mid, buffer);
	_merge_sort(arr, mid, r, buffer);
	merge(arr, l, mid, r, buffer);
}

void merge_sort(vector<int>& arr)
{
	if (arr.size() <= 1)
		return;

	vector<int> buffer(arr.size());
	_merge_sort(arr, 0, arr.size(), buffer);
}

int partition(std::vector<int>& arr, int low, int high) {
	int initialPivotIndex = rand() % (high - low + 1) + low;
	swap(arr[initialPivotIndex], arr[high]); 

	int pivot = arr[high];
	int i = low;

	for (int j = low; j < high; ++j) {
		if (arr[j] <= pivot) {
			std::swap(arr[i], arr[j]);
			i++;
		}
	}

	swap(arr[i], arr[high]);
	return i;
}

void quick_sort(vector<int>& arr, int low, int high)
{
	if (low < high) 
	{
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void countingSort(std::vector<int>& arr) {
	int N = arr.size();

	if (N == 0)
		return;

	int K = *max_element(arr.begin(), arr.end()) + 1;

	std::vector<int> output(N);
	std::vector<int> count(K);

	for (int i = 0; i < N; ++i)
		count[arr[i]]++;

	for (int i = 1; i < K; ++i)
		count[i] += count[i - 1];

	for (int i = N - 1; i >= 0; --i) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0; i < N; ++i)
		arr[i] = output[i];
}



class FindTheDifference {
public:
	char find_the_difference(string s, string t) {
		int s_count[26]{ 0 };
		int t_count[26]{ 0 };

		for (int i = 0; i < s.size(); i++) {
			s_count[s[i] - 'a']++;
			t_count[t[i] - 'a']++;
		}

		t_count[t[t.size() - 1] - 'a']++;

		for (int i = 0; i < 26; i++) {
			if (t_count[i] == s_count[i] + 1)
				return 'a' + i;
		}

		return 'a';
	}
};

class SortedSquares {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int size = nums.size();
		int pivot_index = -1;

		for (int i = 0; i < size - 1; i++)
		{
			if (nums[i] < 0 && nums[i + 1] >= 0)
			{
				pivot_index = i;
				break;
			}
		}

		vector<int> result;
		int negative = pivot_index;
		int positive = pivot_index + 1;

		if (pivot_index == -1 && nums[0] < 0)
		{
			positive = size;
			negative = size - 1;
		}

		while (negative >= 0 && positive < size)
		{
			int curr_neg_square = nums[negative] * nums[negative];
			int curr_pos_square = nums[positive] * nums[positive];

			if (curr_neg_square < curr_pos_square)
			{
				result.push_back(curr_neg_square);
				negative--;
			}
			else
			{
				result.push_back(curr_pos_square);
				positive++;
			}
		}

		while (negative >= 0)
		{
			int curr_neg_square = nums[negative] * nums[negative];
			result.push_back(curr_neg_square);
			negative--;
		}

		while (positive < size)
		{
			int curr_pos_square = nums[positive] * nums[positive];
			result.push_back(curr_pos_square);
			positive++;
		}

		return result;
	}
};

class ContainsDuplicate{
public:
	bool contains_duplicate_with_sort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;
	}

	bool contains_duplicate_with_set(vector<int>& nums) {
		unordered_set<int> nums_set;

		for (int i = 0; i < nums.size();i++)
		{
			if (nums_set.count(nums[i]))
				return true;

			nums_set.insert(nums[i]);
		}

		return false;
	}
};


class MergeTwoArrays {
public:
	 void shiftByIndex(vector<int>& arr, int size, int startingIndex) {
	     for (int i = size - 1; i > startingIndex; i--)
	         arr[i] = arr[i - 1];
	 }

	 void merge_without_array(vector<int>& nums1, int m, vector<int>& nums2, int n) {

	     int left = 0;
	     int right = 0;

	     for (int i = 0; i < m + n; i++) {
	         if (right == n)
	             return;
	         if (left-right == m)
	             break;
	         if (nums1[left] <= nums2[right]) {
	             left++;
	         } else {
	             shiftByIndex(nums1, m + n, left);
	             nums1[left++] = nums2[right++];
	         }
	     }

	     for (int i = left; i < m+n; i++)
	         nums1[i] = nums2[right++];
	 }

	void merge_with_array(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		vector<int> res;
		int left = 0;
		int right = 0;

		while (left < m && right < n) {
			if (nums1[left] <= nums2[right])
				res.push_back(nums1[left++]);
			else
				res.push_back(nums2[right++]);
		}


		while (left < m) {
			res.push_back(nums1[left++]);
		}
		while (right < n) {
			res.push_back(nums2[right++]);
		}



		for (int i = 0; i < m + n; i++)
			nums1[i] = res[i];
	}
};
