#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited, int& current_component_size, int current)
{
	visited[current] = true;

	for (auto neighbour : graph[current]) 
	{
		if (!visited[neighbour])
			dfs(graph, visited, current_component_size, neighbour);
	}

	current_component_size++;
}

void components_count_with_size_divisible_by_k()
{
	int nodes_count, edges_count, K, from, to;

	cin >> nodes_count >> edges_count >> K;

	unordered_map<int, unordered_set<int>> graph;
	for (size_t i = 0; i < edges_count; i++)
	{
		cin >> from >> to;
		graph[from].insert(to);
		graph[to].insert(from);
	}

	vector<bool> visited(nodes_count, false);
	vector<int> components;

	for (size_t i = 0; i < nodes_count; i++)
	{
		if (!visited[i])
		{
			int component_nodes_count = 0;
			dfs(graph, visited, component_nodes_count, i);
			components.push_back(component_nodes_count);
		}
	}

	int result = 0;
	for (size_t i = 0; i < components.size(); i++)
	{
		if (components[i] % K == 0)
			result++;
	}

	cout << result;
}