#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct Edge
{
	int end_index;
	int weight;
};

struct Node
{
	int index;
	int distance;

	Node(int index, int distance)
	{
		this->index = index;
		this->distance = distance;
	}

	bool operator<(const Node& rhs) const {
		return distance < rhs.distance;
	}
};

int longest_path(int nodes_count, unordered_map<int, vector<Edge>>& graph, int start, int end)
{
	vector<int> distances(nodes_count+1, -1);
	distances[start] = 0;

	priority_queue<Node> to_process;
	to_process.push({ start,0 });

	while (!to_process.empty())
	{
		Node current = to_process.top();
		to_process.pop();

		if (current.distance < distances[current.index])
			continue;

		for (Edge current_edge : graph[current.index])
		{
			int new_path_len = current.distance + current_edge.weight;

			if (distances[current_edge.end_index] < new_path_len)
			{
				distances[current_edge.end_index] = new_path_len;
				to_process.push({ current_edge.end_index, new_path_len });
			}
		}
	}

	return distances[end];
}

void long_long()
{
	int nodes_count, edges_count, start, end;
	cin >> nodes_count >> edges_count >> start >> end;

	int from, to, weight;

	unordered_map<int, vector<Edge>> graph;

	for (size_t i = 0; i < edges_count; i++)
	{
		cin >> from >> to >> weight;
		graph[from].push_back({ to,weight });
	}

	cout << longest_path(nodes_count, graph, start, end);
}