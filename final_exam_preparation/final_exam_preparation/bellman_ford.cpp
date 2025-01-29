#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Time Complexity O(V*E)

struct Edge 
{
	int from, to, weight;
};

vector<int> bellman_ford(int start_node, int nodes_count, vector<Edge>& edges) 
{
	vector<int> distances;
	distances[start_node] = 0;

	for (size_t i = 0; i < nodes_count; i++)
	{
		for (Edge edge: edges)
		{
			int new_distance = distances[edge.from] + edge.weight;
			if (distances[edge.from] != INT_MAX && new_distance < distances[edge.to])
				distances[edge.to] = new_distance;
		}
	}

	for (const auto& edge : edges) {
		if (distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to])
			throw logic_error("Negative cycle!");
	}

	return distances;
}