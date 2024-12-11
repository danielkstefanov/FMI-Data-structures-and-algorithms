#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;


void bfs(vector<bool>& visited, unordered_map<int, unordered_set<int>>& graph, int s) {

	queue<int> currentLevel;
	visited[s] = true;
	currentLevel.push(s);

	int distance = 1;

	while (currentLevel.size())
	{
		int levelSize = currentLevel.size();

		for (int i = 0; i < levelSize;i++)
		{
			int currentNode = currentLevel.front();
			currentLevel.pop();

			for (int neighbour : graph[currentNode])
			{
				if (!visited[neighbour]) {
					visited[neighbour] = true;
					currentLevel.push(neighbour);
				}
			}

		}

		distance++;
	}
}

int main()
{
	int tests, nodes, edges, x, y;
	cin >> tests;

	for (size_t i = 0; i < tests; i++)
	{
		cin >> nodes >> edges;
		int components = 0;

		vector<bool> visited(nodes, false);
		unordered_map<int, unordered_set<int>> graph;

		for (int i = 0; i < edges;i++)
		{
			cin >> x >> y;
			graph[x].insert(y);
			graph[y].insert(x);
		}

		for (int i = 0; i < visited.size(); i++)
		{
			if (!visited[i])
			{
				bfs(visited, graph, i);
				components++;
			}
		}

		cout << components << " ";
	}
	return 0;
}