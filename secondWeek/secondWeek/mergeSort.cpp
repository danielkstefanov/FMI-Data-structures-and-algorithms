//#include <iostream>
//#include <vector>
//
//void mergeSort(std::vector<int>& arr)
//{
//	std::vector<int> temp(arr.size());
//	mergeSort(arr, temp, 0, arr.size() - 1);
//}
//
//void mergeSort(std::vector<int>& arr, std::vector<int>& temp, int low, int high)
//{
//	if (low < high)
//	{
//		int mid = (high + low) / 2;
//
//		mergeSort(arr, temp, low, mid);
//		mergeSort(arr, temp, mid + 1, high);
//		merge(arr, temp, low, mid + 1, high);
//	}
//}
//
//
//void merge(std::vector<int>& arr, std::vector<int>& temp, int start, int mid, int end)
//{
//	int left = start;
//	int right = mid;
//	int currentIndex = left;
//	
//	while (left <= mid-1 && right <= end)
//	{
//		if (arr[left] < arr[right])
//		{
//			temp[currentIndex++] = arr[left++];
//		}
//		else 
//		{
//			temp[currentIndex++] = arr[right++];
//		}
//	}
//
//	while (left <= mid-1) 
//	{
//		temp[currentIndex++] = arr[left++];
//	}
//
//	while (right <= end)
//	{
//		temp[currentIndex++] = arr[right++];
//	}
//
//	for (size_t i = start; i <= end; i++)
//		arr[i] = temp[i];
//}