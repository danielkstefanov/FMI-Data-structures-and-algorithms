#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int dfs(int current, int& even_nodes_components, int& current_component_nodes, unordered_set<int>& visited, unordered_map<int, unordered_set<int>>& graph)
{
	visited.insert(current);

	int kids_count = 0;

	for (int neighbour : graph[current])
	{
		if (!visited.count(neighbour))
			kids_count += dfs(neighbour, even_nodes_components, current_component_nodes,  visited, graph);
	}

	if (kids_count && (kids_count+1 )%2==0)
	{
		even_nodes_components++;
		return 0;
	}

	return kids_count + 1;
}

void maxEdgeRemoveCount() {
	int nodes_count, edges_count;
	cin >> nodes_count >> edges_count;

	unordered_map<int, unordered_set<int>> graph;
	unordered_set<int> visited;

	int start, end;

	for (size_t i = 0; i < edges_count; i++)
	{
		cin >> start >> end;
		graph[start].insert(end);
		graph[end].insert(start);
	}


	int even_nodes_components = 0;
	int current_component_nodes = 0;

	dfs(1, even_nodes_components, current_component_nodes, visited, graph);

	cout << even_nodes_components-1;
}
