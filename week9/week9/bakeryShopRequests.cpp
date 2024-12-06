#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Request
{
	int startTime;
	int duration;
	int index;

	Request(int startTime, int duration, int index)
	{
		this->startTime = startTime;
		this->duration = duration;
		this->index = index;
	}
};

struct RequestMinComparerByStart {

	bool operator()(const Request& r1, const Request& r2) {
		return r1.startTime > r2.startTime;
	}
};

struct RequestMaxComparerByDuration {

	bool operator()(const Request& r1, const Request& r2) {

		if(r1.duration == r2.duration)
			return r1.index > r2.index;
		
		return r1.duration > r2.duration;
	}
};


void bakeryShop() {

	int N;
	cin >> N;

	priority_queue<Request, vector<Request>, RequestMinComparerByStart> toCome;
	priority_queue<Request, vector<Request>, RequestMaxComparerByDuration> active;

	vector<int> result;

	for (size_t i = 0; i < N; i++)
	{
		int startTime, duration;
		cin >> startTime >> duration;

		toCome.push(Request(startTime, duration, i));
	}

	int currentTime = toCome.top().startTime;

	while (toCome.size() || active.size())
	{
		while (toCome.size() && toCome.top().startTime <= currentTime)
		{
			active.push(toCome.top());
			toCome.pop();
		}

		if (active.size())
		{
			Request currentToPrepare = active.top();
			active.pop();
			result.push_back(currentToPrepare.index);
			currentTime += currentToPrepare.duration;
		}
		else
		{
			currentTime = toCome.top().startTime;
		}

	}

	for (int el: result)
		cout << el << " ";
}
