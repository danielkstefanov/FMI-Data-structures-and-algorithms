#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
	struct Edge {
		int to;
		int weight;

		Edge(int to, int weight) : to(to), weight(weight) {}

		bool operator<(const Edge& other) const {
			return weight > other.weight;
		}
	};

	int prim(int n, int start, unordered_map<int, vector<Edge>>& graph) {
		priority_queue<Edge> pq;
		unordered_set<int> visited;
		pq.push({ start, 0 });

		int totalWeight = 0;

		while (!pq.empty() && visited.size() < n) {
			auto current = pq.top();
			pq.pop();
			if (visited.count(current.to))
				continue;

			visited.insert(current.to);
			totalWeight += current.weight;
			for (auto& adj : graph[current.to]) {
				if (visited.count(adj.to))
					continue;

				pq.push(adj);
			}
		}

		return totalWeight;
	}

	int minCostConnectPoints(vector<vector<int>>& points) {
		unordered_map<int, vector<Edge>> graph;
		for (int i = 0; i < points.size(); i++) {

			for (int j = 0; j < points.size(); j++) {
				if (i == j)
					continue;

				int x1 = points[i][0];
				int y1 = points[i][1];

				int x2 = points[j][0];
				int y2 = points[j][1];

				int length = abs(x2 - x1) + abs(y2 - y1);

				graph[i].push_back({ j, length });
			}
		}

		return prim(points.size(), 0, graph);
	}

};