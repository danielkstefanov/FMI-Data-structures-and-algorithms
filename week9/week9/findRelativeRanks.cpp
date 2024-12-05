#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
	vector<string> result(score.size());

	priority_queue<pair<int, int>> pq;

	for (size_t i = 0; i < score.size(); i++)
		pq.push({ score[i],i });

	for (size_t i = 1; i <= score.size(); i++)
	{
		pair<int, int> currentPos = pq.top();
		pq.pop();

		string current = to_string(i);

		if (i == 1)
			current = "Gold Medal";
		else if (i == 2)
			current = "Silver Medal";
		else if (i == 3)
			current = "Bronze Medal";

		result[currentPos.second] = current;
	}

	return result;
}