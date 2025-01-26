#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

long long count_of_pancakes_in_time(long long time, const vector<int>& cookers)
{
	long long result = 0;

	for (size_t i = 0; i < cookers.size(); i++)
		result += time / cookers[i];

	return result;
}

void pancakes()
{
	long long pancakes_count, cookers_count, current_cooker;
	cin >> pancakes_count >> cookers_count;

	vector<int> cookers;

	long long slowest_cooker = INT_MIN;

	for (size_t i = 0; i < cookers_count; i++)
	{
		cin >> current_cooker;
		cookers.push_back(current_cooker);
		if (current_cooker > slowest_cooker)
			slowest_cooker = current_cooker;
	}

	long long left = 0;
	long long right = slowest_cooker * pancakes_count;

	long long result = -1;

	while (left <= right)
	{
		long long middle = left + (right - left) / 2;
		if (count_of_pancakes_in_time(middle, cookers) >= pancakes_count)
		{
			right = middle - 1;
			result = middle;
		}
		else
		{
			left = middle + 1;
		}
	}

	cout << result;
}

struct ComparePair {
	bool operator()(const std::pair<long long, long long>& lhs, const std::pair<long long, long long>& rhs) {
		return lhs.first > rhs.first;
	}
};

void not_optimal_but_first_in_mind()
{
	long long pancakes_count, cookers_count, current_cooker;
	cin >> pancakes_count >> cookers_count;

	priority_queue <pair<long long, long long>, vector <pair<long long, long long>>, ComparePair> pq;

	for (size_t i = 0; i < cookers_count; i++)
	{
		cin >> current_cooker;
		pq.push({ current_cooker ,current_cooker });
	}

	long long time = 0;

	for (size_t i = 0; i < pancakes_count; i++)
	{
		pair<long long, long long> best_cooker = pq.top();
		time = best_cooker.first;
		pq.pop();
		pq.push({ best_cooker.first + best_cooker.second, best_cooker.second });
	}

	cout << time;
}