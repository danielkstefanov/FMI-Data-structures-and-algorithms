#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int findMin(queue<int>& currentSubset)
{
	int smallest = currentSubset.front();

	for (size_t i = 0; i < currentSubset.size(); i++)
	{
		int current = currentSubset.front();
		currentSubset.pop();

		if (current < smallest)
			smallest = current;

		currentSubset.push(current);
	}

	return smallest;
}

void smallestElementsSumBySubArrays() {
	int N, k;
	cin >> N >> k;

	if (k == 0) {
		cout << 0;
		return;
	}


	queue<int> currentSubset;

	for (size_t i = 0; i < k; i++)
	{
		int current;
		cin >> current;

		currentSubset.push(current);
	}

	long sum = 0;
	int minimalElement = findMin(currentSubset);

	bool toSearchNewMin = false;

	for (size_t i = 0; i <= N - k; i++)
	{
		if (toSearchNewMin)
		{
			minimalElement = findMin(currentSubset);
			toSearchNewMin = false;
		}

		int current = currentSubset.front();
		currentSubset.pop();


		sum += minimalElement;

		if (i != N - k)
		{
			int currentToAdd;
			cin >> currentToAdd;
			currentSubset.push(currentToAdd);
			if (currentToAdd < minimalElement)
				minimalElement = currentToAdd;
		}

		if (current == minimalElement)
			toSearchNewMin = true;
	}

	cout << sum;
}