#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Edge {
	int index, to;
	long long efford, profit;

	Edge(int index, int to, long long efford, long long profit) : index(index), to(to), efford(efford), profit(profit) {}

	bool operator<(const Edge& other) const {
		if (efford == other.efford)
			return profit < other.profit;

		return efford > other.efford;
	}
};

vector<Edge> prim(int n, int start, unordered_map<int, vector<Edge>>& graph) {
	priority_queue<Edge> pq;
	unordered_set<int> visited;
	pq.push({ -1, start, 0, 0 });

	vector<Edge> mstEdges;

	while (!pq.empty() && visited.size() < n) {
		auto current = pq.top();
		pq.pop();
		if (visited.count(current.to)) {
			continue;
		}

		visited.insert(current.to);
		mstEdges.push_back(current);
		for (auto& adj : graph[current.to]) {
			if (visited.count(adj.to)) {
				continue;
			}
			pq.push(adj);
		}
	}

	return mstEdges;
}

void best_roads_to_built() {
	int cities_count, roads_count;
	cin >> cities_count >> roads_count;
	unordered_map<int, vector<Edge>> graph;

	int from, to;
	long long efford, profit;

	for (int i = 1; i <= roads_count; i++)
	{
		cin >> from >> to >> efford >> profit;

		graph[from].push_back({ i,to,efford,profit });
		graph[to].push_back({ i,from,efford,profit });
	}

	vector<Edge> built_roads = prim(cities_count, 1, graph);

	for (size_t i = 1; i < built_roads.size(); i++)
		cout << built_roads[i].index << '\n';
}