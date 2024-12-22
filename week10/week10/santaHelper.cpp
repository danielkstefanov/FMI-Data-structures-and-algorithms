#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(int current, int& current_component, vector<int>& visited, unordered_map<int, unordered_set<int>>& graph)
{
	visited[current] = current_component;

	for (int neighbour : graph[current])
	{
		if (visited[neighbour] == -1)
			dfs(neighbour, current_component, visited, graph);
	}
}

void santaHelper() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int houses_count, streets_count;
	cin >> houses_count >> streets_count;

	unordered_map<int, unordered_set<int>> graph;
	vector<int> visited(houses_count + 1, -1);

	int start, end;

	for (size_t i = 0; i < streets_count; i++)
	{
		cin >> start >> end;
		graph[start].insert(end);
		graph[end].insert(start);
	}

	int currentComponent = 1;

	for (size_t i = 1; i <= houses_count; i++)
	{
		if (visited[i] == -1)
			dfs(i, currentComponent, visited, graph);

		currentComponent++;
	}

	int queries;
	cin >> queries;

	for (size_t i = 0; i < queries; i++)
	{
		cin >> start >> end;
		cout << (visited[start] == visited[end] ? 1 : 0) << ' ';
	}

}
