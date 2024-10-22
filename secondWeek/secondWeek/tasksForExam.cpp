#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//2023-2024

size_t encode(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		return ch - 'A' + 10;
	}
	else
	{
		return ch - 'a' + 37;
	}
}

void uniqueSymbolIndeces()
{
	string str;
	cin >> str;
	vector<int> count(62, 0);

	for (int i = 0;i < str.length();i++)
		count[encode(str[i])]++;

	for (int i = 0;i < str.length();i++)
	{
		if (count[encode(str[i])] == 1)
			cout << i << ' ';
	}
}

//2022-2023
void queueNumbers() 
{
	int n;
	cin >> n;
	vector<pair<int, int>> nums;
	for (size_t i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums.push_back({ num, i });
	}

	sort(nums.begin(), nums.end());


	for (size_t i = 0; i < n; i++)
		nums[i].first = i;

	sort(nums.begin(), nums.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.second < b.second; });


	for (size_t i = 0; i < n; i++)
		cout << nums[i].first << ' ';
}

int partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low;          

	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(arr[i], arr[j]); 
			i++;
		}
	}

	swap(arr[i], arr[high]);

	return i;
}

void quickSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void getUniqueByIncreasingOrder() 
{
	int n;
	cin >> n;

	vector<int> nums(n);

	for (size_t i = 0; i < n; i++)
		cin >> nums[i];

	quickSort(nums, 0, nums.size() - 1);

	for (size_t i = 0; i < n - 1; i++)
	{
		if (nums[i] != nums[i + 1])
			cout << nums[i];
	}

	cout << nums[n - 1];
}