#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int bfs(unordered_map<int, unordered_set<int>>& graph, vector<int>& groups, int start, int searchedGroup)
{
	queue<int> q;
	unordered_set<int> visited;
	q.push(start);
	visited.insert(start);

	int distance = 0;

	while (!q.empty()) {
		int level_size = q.size();

		for (int i = 0; i < level_size; ++i) {
			int current = q.front();
			q.pop();
			
			if (groups[current] == searchedGroup && current != start)
				return distance;

			for (int neighbor : graph[current]) {
				if (!visited.count(neighbor)) {
					visited.insert(neighbor);
					q.push(neighbor);
				}
			}
		}
		distance++;
	}

	return INT_MAX;
}

void shortestPathToFriendInGroup()
{
	int nodes, edges, start, end, group;
	cin >> nodes >> edges;

	unordered_map<int, unordered_set<int>> graph;
	vector<int> groups(nodes + 1, -1);

	for (size_t i = 0; i < edges; i++)
	{
		cin >> start >> end;
		graph[start].insert(end);
		graph[end].insert(start);
	}

	for (size_t i = 1; i <= nodes; i++)
	{
		cin >> group;
		groups[i] = group;
	}

	int searchedGroup;
	cin >> searchedGroup;

	int shortestPath = INT_MAX;

	for (size_t i = 1; i <= nodes; i++)
	{
		if (groups[i] == searchedGroup) {
			int shortestPathFromThisNode = bfs(graph,groups,i,searchedGroup);

			if (shortestPathFromThisNode < shortestPath)
				shortestPath = shortestPathFromThisNode;
		}
	}

	cout << shortestPath;
}