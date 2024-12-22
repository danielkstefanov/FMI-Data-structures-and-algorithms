#include <iostream>
#include <vector>

using namespace std;


class MySolution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
		int k) {

		vector<vector<int>> distances(n, vector<int>(k + 2, INT_MAX));
		distances[src][0] = 0;

		for (int i = 0; i < n - 1; ++i) {
			for (const vector<int>& flight : flights) {

				int start = flight[0];
				int end = flight[1];
				int weight = flight[2];

				for (int j = 0; j < k + 1; j++) {

					if (distances[start][j] == INT_MAX)
						continue;

					int new_path_with_j_len = distances[start][j] + weight;

					if (new_path_with_j_len <
						distances[end][j + 1]) {
						distances[end][j + 1] = new_path_with_j_len;
					}
				}
			}
		}

		int min_len = INT_MAX;

		for (int current_path_len : distances[dst])
		{
			if (current_path_len < min_len)
				min_len = current_path_len;
		}

		return min_len == INT_MAX ? -1 : min_len;
	}

};


class RightSolution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<int> distances(n, INT_MAX);
		distances[src] = 0;

		for (int i = 0; i <= k; i++) {

			vector<int> nextRow(distances);

			for (auto& edge : flights) {
				if (distances[edge[0]] != INT_MAX) {
					nextRow[edge[1]] = min(nextRow[edge[1]], distances[edge[0]] + edge[2]);
				}
			}

			distances = std::move(nextRow);
		}

		if (distances[dst] == INT_MAX) {
			return -1;
		}

		return distances[dst];
	}
};