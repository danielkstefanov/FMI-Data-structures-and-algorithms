#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

bool dfs(vector<char>& visited, unordered_map<int, unordered_set<int>>& graph, int current) {

	visited[current] = 'o';

	for (int neighbour : graph[current]) {
		if (visited[neighbour] == 'o') {
			return true;
		}
		else if (visited[neighbour] == 'c')
		{
			continue;
		}
		else if (dfs(visited, graph, neighbour))
		{
			return true;
		}
	}

	visited[current] = 'c';
	return false;
}

bool hasCycle(int nodes, unordered_map<int, unordered_set<int>>& graph) 
{
	vector<char> visited(nodes + 1, 'u');

	for (size_t i = 1; i <= graph.size(); i++)
	{
		if (visited[i] != 'u')
			continue;

		if (dfs(visited, graph, i))
			return true;
	}

	return false;
}

void checkForCycles()
{

	int tests, nodes, edges, start, end, weight;
	cin >> tests;

	for (size_t i = 0; i < tests; i++)
	{
		cin >> nodes >> edges;
		unordered_map<int, unordered_set<int>> graph;

		for (size_t i = 0; i < edges; i++)
		{
			cin >> start >> end >> weight;
			graph[start].insert(end);
		}

		cout << (hasCycle(nodes,graph) ? "true" : "false") << ' ';

	}
}