#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Edge
{
	int to;
	int weight;

	bool operator < (const Edge& other) const
	{
		return weight > other.weight;
	}
};


int prims(int n, vector<vector<int>> edges, int start) {

	unordered_map<int, vector<Edge>> graph;

	for (int i = 0; i < edges.size(); i++)
	{
		graph[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
		graph[edges[i][1]].push_back({ edges[i][0], edges[i][2] });
	}

	unordered_set<int> visited_nodes;
	priority_queue<Edge> pq;
	pq.push({ start, 0 });

	int edges_sum = 0;

	while (!pq.empty() && visited_nodes.size() < n)
	{
		Edge current_best_edge = pq.top();
		pq.pop();

		if (visited_nodes.count(current_best_edge.to))
			continue;

		visited_nodes.insert(current_best_edge.to);
		edges_sum += current_best_edge.weight;

		for (auto& adj : graph[current_best_edge.to]) {
			if (visited_nodes.count(adj.to))
				continue;

			pq.push(adj);
		}
	}

	return edges_sum;
}