#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int start, int end) 
{
	int pivot = arr[end];
	int i = start;

	for (int j = 0;j < end;j++) 
	{
		if (arr[j] <= pivot) 
		{
			std::swap(arr[j], arr[i]);
			i++;
		}
	}

	std::swap(arr[i],arr[end]);
}

void quickSort(std::vector<int>& arr, int start, int end) 
{
	while (start < end) 
	{
		int pi = partition(arr, start, end);

		quickSort(arr, start, pi-1);
		quickSort(arr, pi+1, end);
	}
}
