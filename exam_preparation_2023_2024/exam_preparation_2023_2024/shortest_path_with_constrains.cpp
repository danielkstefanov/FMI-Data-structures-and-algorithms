#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(int start, int end, unordered_map<int, unordered_set<int>>& graph , unordered_set<int>& to_not_include)
{
	int result = 0;

	queue<int> nodes;
	unordered_set<int> visited;
	visited.insert(start);
	nodes.push(start);

	while (!nodes.empty())
	{
		int current_level = nodes.size();
		bool is_found = false;
		for (size_t i = 0; i < current_level; i++)
		{
			int current = nodes.front();
			nodes.pop();

			if (current == end)
				return result;

			for (int neightbour: graph[current])
			{
				if (!to_not_include.count(neightbour) && !visited.count(neightbour))
				{
					nodes.push(neightbour);
					visited.insert(neightbour);
				}
			}
		}

		result++;
	}

	return result;
}

void shortest_path_len_with_constrains() {
	int nodes_count, edges_count, from, to, p, k, to_skip;
	cin >> nodes_count >> edges_count;

	unordered_map<int, unordered_set<int>> graph;

	for (size_t i = 0; i < edges_count; i++)
	{
		cin >> from >> to;
		graph[from].insert(to);
		graph[to].insert(from);
	}

	cin >> p;
	vector<int> to_include(p, -1);
	for (size_t i = 0; i < p; i++)
		cin >> to_include[i];

	cin >> k;
	unordered_set<int> to_not_include;
	for (size_t i = 0; i < k; i++)
	{
		cin >> to_skip;
		to_not_include.insert(to_skip);
	}

	int res = 0;
	for (size_t i = 2; i < p; i++)
		to_not_include.insert(to_include[i]);

	for (size_t i = 0; i < p - 1; i++)
	{
		res += bfs(to_include[i], to_include[i+1], graph, to_not_include);

		if(i+2 < p)
			to_not_include.erase(to_include[i+2]);
	}

	cout << res;
}







struct Edge {
	int from, to, weight;
};

std::vector<int> bellman_ford(int start, int nodesCount, const std::vector<Edge>& edges) {
	std::vector<int> distances(nodesCount, INT_MAX);
	distances[start] = 0;

	for (int i = 0; i < nodesCount - 1; ++i) {
		for (const auto& edge : edges) {
			if (distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to]) {
				distances[edge.to] = distances[edge.from] + edge.weight;
			}
		}
	}

	for (const auto& edge : edges) {
		if (distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to]) {
			throw std::logic_error("Oh, no negative cycle...");
		}
	}

	return distances;
}



struct Edge {
	int to, weight;
};

void topologicalSort(
	int current,
	const std::unordered_map<int, std::vector<Edge>>& graph,
	std::vector<bool>& visited,
	std::stack<int>& topologicalSortStack
) {
	visited[current] = true;
	if (graph.find(current) != graph.end()) {
		for (const auto& edge : graph.at(current)) {
			if (!visited[edge.to]) {
				topologicalSort(edge.to, graph, visited, topologicalSortStack);
			}
		}
	}
	topologicalSortStack.push(current);
}

std::vector<int> dagShortedPath(int start, int V, const std::unordered_map<int, std::vector<Edge>>& graph) {
	std::vector<int> distances(V, INT_MAX);
	distances[start] = 0;

	std::stack<int> topologicalSortStack;
	std::vector<bool> visited(V, false);

	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			topologicalSort(i, graph, visited, topologicalSortStack);
		}
	}

	while (!topologicalSortStack.empty()) {
		int u = topologicalSortStack.top();
		topologicalSortStack.pop();

		if (distances[u] != INT_MAX && graph.find(u) != graph.end()) {
			for (const auto& edge : graph.at(u)) {
				if (distances[u] + edge.weight < distances[edge.to]) {
					distances[edge.to] = distances[u] + edge.weight;
				}
			}
		}
	}

	return distances;
}