#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr)
{
	int higherBoundForInnerCycle = arr.size() - 1;

	for (size_t i = 0;i < arr.size(); i++)
	{
		int lastSwapIndex = -1;

		for (size_t j = 0; j < higherBoundForInnerCycle;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				lastSwapIndex = j;
			}
		}

		if (lastSwapIndex == -1)
			return;

		higherBoundForInnerCycle = lastSwapIndex;
	}
}