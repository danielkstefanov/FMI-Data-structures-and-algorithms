#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {

		priority_queue<int> pq;

		for (int el : stones)
			pq.push(el);

		while (pq.size() > 1)
		{
			int first = pq.top();
			pq.pop();

			int second = pq.top();
			pq.pop();

			if (first != second)
				pq.push(first - second);

		}

		if (!pq.size())
			return 0;

		return pq.top();
	}
};