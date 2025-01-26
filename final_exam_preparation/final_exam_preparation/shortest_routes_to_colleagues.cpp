#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

void bfs(int start_node, unordered_map<int, unordered_set<int>>& graph, vector<int>& distances)
{
	distances[start_node] = 0;
	queue<int> current_level;
	current_level.push(start_node);
	int distance = 1;

	while (current_level.size())
	{
		int current_level_size = current_level.size();

		for (size_t i = 0; i < current_level_size; i++)
		{
			int current_node = current_level.front();
			current_level.pop();

			for (int neightbour: graph[current_node])
			{
				if (distances[neightbour] != -1)
					continue;

				distances[neightbour] = distance;
				current_level.push(neightbour);
			}
		}

		distance++;
	}
	
}

void shortest_paths_to_colleagues()
{
	int queries_count, nodes_count, edges_count, start_node, from, to;

	cin >> queries_count;

	for (size_t i = 0; i < queries_count; i++)
	{
		cin >> nodes_count >> edges_count;
		unordered_map<int, unordered_set<int>> graph;

		for (size_t j = 0; j < edges_count; j++)
		{
			cin >> from >> to;
			graph[from].insert(to);
			graph[to].insert(from);
		}

		cin >> start_node;
		vector<int> distances(nodes_count+1, -1);
		bfs(start_node, graph, distances);

		for (size_t j = 1; j <= nodes_count; j++) 
		{
			if (j != start_node)
				cout << (distances[j] == -1 ? -1 : distances[j]*6) << ' ';
		}

		cout << '\n';
	}
}