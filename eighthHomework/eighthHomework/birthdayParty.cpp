#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct Friend
{
	int arrive;
	int leave;
	int index;
	int sittingIndex;

	Friend(int arrive, int leave, int index)
	{
		this->arrive = arrive;
		this->leave = leave;
		this->index = index;
		this->sittingIndex = -1;
	}
};

struct FriendMaxComparatorForArrive {

	bool operator()(const Friend& f1, const Friend& f2) {
		return f1.arrive > f2.arrive;
	}
};

struct FriendMaxComparatorForLeave {

	bool operator()(const Friend& f1, const Friend& f2) {
		return f1.leave > f2.leave;
	}
};

priority_queue<Friend, vector<Friend>, FriendMaxComparatorForArrive> toCome;
priority_queue<Friend, vector<Friend>, FriendMaxComparatorForLeave> sitting;
priority_queue<int, vector<int>, greater<int>> freeIndeces;

int smallestChair(vector<vector<int>>& times, int targetFriend) {

	for (size_t i = 0; i < times.size();i++)
	{
		freeIndeces.push(i);
		Friend f(times[i][0], times[i][1], i);
		toCome.push(f);
	}

	while (toCome.size())
	{
		Friend f = toCome.top();
		toCome.pop();

		while (sitting.size() && f.arrive >= sitting.top().leave)
		{
			freeIndeces.push(sitting.top().sittingIndex);
			sitting.pop();
		}

		f.sittingIndex = freeIndeces.top();
		freeIndeces.pop();

		if (f.index == targetFriend)
			return f.sittingIndex;
		sitting.push(f);
	}

	return -1;
}

void birthdayParty() 
{
	int N, target;
	cin >> N;
	vector<vector<int>> times;

	for (size_t i = 0; i < N; i++)
	{
		int first;
		int second;

		cin >> first >> second;
		times.push_back({ first,second });
	}

	cin >> target;

	cout << smallestChair(times, target);
}