#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class MedianFinder {
public:

	priority_queue<int> lower;
	priority_queue<int, vector<int>, greater<int>> upper;

	MedianFinder() 
	{
		this->lower = priority_queue<int>();
		this->upper = priority_queue<int, vector<int>, greater<int>>();
	}

	void addNum(int num)
	{
		if (lower.size() == 0) 
		{
			lower.push(num);
			return;
		}

		if (lower.top() > num) 
			lower.push(num);
		else
			upper.push(num);

		if (lower.size() > upper.size() + 1)
		{
			int toSave = lower.top();
			lower.pop();
			upper.push(toSave);
		}
		else if(lower.size() + 1 < upper.size())
		{
			int toSave = upper.top();
			upper.pop();
			lower.push(toSave);
		}
	}

	double findMedian()
	{
		if (lower.size() == upper.size())
			return (double(lower.top()) + double(upper.top())) / 2;
		else if (lower.size() > upper.size())
			return lower.top();

		return upper.top();
	}
};