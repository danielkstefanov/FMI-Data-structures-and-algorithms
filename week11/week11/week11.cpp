#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


namespace Dijkstra
{

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
			return distance > rhs.distance;
		}
	};


	vector<int> dijkstra(int start, int nodes_count, unordered_map<int, std::vector<Edge>>& graph)
	{
		vector<int> distances(nodes_count, INT_MAX);
		distances[start] = 0;

		priority_queue<Node> to_process;
		to_process.push({ start,0 });

		while (!to_process.empty())
		{
			Node current = to_process.top();
			to_process.pop();

			if (current.distance > distances[current.index])
				continue;

			for (Edge current_edge : graph[current.index])
			{
				int new_path_len = current.distance + current_edge.weight;

				if (distances[current_edge.end_index] > new_path_len)
				{
					distances[current_edge.end_index] = new_path_len;
					to_process.push({ current_edge.end_index, new_path_len });
				}
			}
		}

		return distances;
	}
}


namespace Bellman_ford 
{
	struct Edge
	{
		int from, to, weight;
	};

	vector<int> bellman_ford(int start, int nodes_count, const vector<Edge>& edges) 
	{
		vector<int> distances(nodes_count, INT_MAX);
		distances[start] = 0;

		for (size_t i = 0; i < nodes_count-1; i++)
		{
			for (Edge current_edge: edges)
			{
				int new_path_distance = distances[current_edge.from] + current_edge.weight;

				if (distances[current_edge.to] > new_path_distance)
					distances[current_edge.to] = new_path_distance;
			}
		}


		for (Edge current_edge: edges)
		{
			if (distances[current_edge.from] != INT_MAX && distances[current_edge.from] + current_edge.weight < distances[current_edge.to])
				throw logic_error("negative cycle");
		}

		return distances;
	}
}