#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int bfs(int start_node, int end_node, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& to_skip)
{
	unordered_set<int> visited;
	visited.insert(start_node);
	
	queue<int> current_level;
	current_level.push(start_node);
	
	int distance = 1;

	while (current_level.size())
	{
		int current_level_size = current_level.size();

		for (size_t i = 0; i < current_level_size; i++)
		{
			int current = current_level.front();
			current_level.pop();

			for (int neightbour: graph[current])
			{
				if (neightbour == end_node)
					return distance;

				if (to_skip.count(neightbour) || visited.count(neightbour))
					continue;

				visited.insert(neightbour);
				current_level.push(neightbour);
			}
		}

		distance++;
	}

	return -1;
}

void cheapest_road()
{
	int nodes_count, edges_count, from, to, attractions_count, current_attraction;
	cin >> nodes_count >> edges_count;

	unordered_map<int, unordered_set<int>> graph;

	for (size_t i = 0; i < edges_count; i++)
	{
		cin >> from >> to;
		graph[from].insert(to);
	}

	cin >> attractions_count;
	vector<int> attractions;

	unordered_set<int> to_skip;

	for (size_t i = 0; i < attractions_count; i++)
	{
		cin >> current_attraction;
		attractions.push_back(current_attraction);
		if(i >= 2)
			to_skip.insert(current_attraction);
	}

	int distance = 0;

	for (size_t i = 1; i < attractions_count; i++)
	{
		int current_path_len = bfs(attractions[i-1], attractions[i], graph, to_skip);
		
		if (current_path_len == -1)
		{
			distance = -1;
			break;
		}

		distance += current_path_len;
		to_skip.erase(attractions[i]);
	}

	cout << distance;
}