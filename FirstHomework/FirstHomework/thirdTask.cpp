#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int simple_strcmp(const char* str1, const char* str2) {
	while (*str1 && (*str1 == *str2)) {
		++str1;
		++str2;
	}
	return *(unsigned char*)str1 - *(unsigned char*)str2;
}

bool toSwap(pair<string, unsigned>& firstStudent, pair<string, unsigned>& secondStudent) 
{
	return firstStudent.second < secondStudent.second || (firstStudent.second == secondStudent.second && simple_strcmp(firstStudent.first.c_str(), secondStudent.first.c_str()) > 0);
}


int partition(vector<pair<string,unsigned>>& arr, int low, int high)
{
	pair<string, unsigned> pivot = arr[high];
	int i = low;           // Index of the smaller element

	for (int j = low; j < high; j++)
	{
		if (toSwap(pivot, arr[j]))
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}

	swap(arr[i], arr[high]);
	return i;
}

void quick_sort(vector<pair<string,unsigned>>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void thirdTask(){
	unsigned n;
	cin >> n;

	vector<pair<string, unsigned>> students;

	for (size_t i = 0; i < n; i++)
	{
		pair<string, unsigned> currentStudent;
		cin >> currentStudent.first;
		students.push_back(currentStudent);
	}

	for (size_t i = 0; i < n; i++)
		cin >> students[i].second;

	quick_sort(students, 0, n-1);

	for (size_t i = 0; i < n; i++)
		cout << students[i].first << ' ' << students[i].second << endl;
}