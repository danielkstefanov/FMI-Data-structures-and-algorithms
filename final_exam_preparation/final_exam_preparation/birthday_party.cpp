#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Guest
{
	int index, come_time, go_time, sitting_index;
};

struct GuestsArriveComparator {

	bool operator () (const Guest& lhs, const Guest& rhs) const
	{
		return lhs.come_time > rhs.come_time;
	}
};

struct GuestsGoComparator {

	bool operator () (const Guest& lhs, const Guest& rhs) const
	{
		return lhs.go_time > rhs.go_time;
	}
};


void birthday_party()
{
	int guests_count, start, end, disliked;
	cin >> guests_count;

	priority_queue<Guest, vector<Guest>, GuestsArriveComparator> to_come;
	priority_queue<Guest, vector<Guest>, GuestsGoComparator> to_go;
	priority_queue<int, vector<int>, greater<int>> free_chairs;

	for (int i = 0; i < guests_count; i++)
	{
		cin >> start >> end;
		free_chairs.push(i);
		to_come.push({ i,start,end, -1 });
	}

	cin >> disliked;

	while (to_come.size())
	{
		Guest current_to_come = to_come.top();
		to_come.pop();

		while (to_go.size() && to_go.top().go_time <= current_to_come.come_time)
		{
			free_chairs.push(to_go.top().sitting_index);
			to_go.pop();
		}

		current_to_come.sitting_index = free_chairs.top();
		free_chairs.pop();
		to_go.push(current_to_come);

		if (current_to_come.index == disliked)
		{
			cout << current_to_come.sitting_index;
			break;
		}

	}
}