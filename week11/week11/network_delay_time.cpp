#include <vector>

using namespace std;

class Solution {
public:
	struct Edge {
		int to;
		int weight;
	};

	struct Node {
		int index;
		int distance;

		bool operator<(const Node& rhs) const {
			return distance > rhs.distance;
		}
	};

	int networkDelayTime(vector<vector<int>>& times, int n, int k) {

		vector<int> distances(n + 1, INT_MAX);
		distances[k] = 0;

		for (size_t i = 0; i < n - 1; i++)
		{
			for (const vector<int>& current_edge : times)
			{
				if (distances[current_edge[0]] == INT_MAX)
					continue;

				int new_path_distance = distances[current_edge[0]] + current_edge[2];

				if (distances[current_edge[1]] > new_path_distance)
					distances[current_edge[1]] = new_path_distance;
			}
		}

		int longest_path = 0;

		for (size_t i = 1; i <= n; i++)
		{
			if (distances[i] == INT_MAX)
				return -1;

			if (distances[i] > longest_path)
				longest_path = distances[i];
		}


		return longest_path;
	}
};