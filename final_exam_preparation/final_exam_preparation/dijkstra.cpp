#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Greedy algorithm
// Doesn't work for graphs with negative edges
// Time complexity O((V+E)*logE)

struct Edge 
{
	int to, weight;
};

struct Node
{
	int index, distance;

	bool operator < (const Node& other) const 
	{
		return distance > other.distance;
	}
};

vector<int> dijkstra(int nodes_count,int start_node, unordered_map<int, vector<Edge>> graph) 
{
	vector<int> distances(nodes_count, INT_MAX);
	distances[start_node] = 0;

	priority_queue<Node> pq;
	pq.push({ start_node, 0 });

	while (pq.size())
	{
		Node current_node = pq.top();
		pq.pop();

		if (current_node.distance > distances[current_node.index])
			continue;

		for (Edge edge : graph[current_node.index])
		{
			int new_length = current_node.distance + edge.weight;

			if (distances[edge.to] > new_length)
			{
				distances[edge.to] = new_length;
				pq.push({ edge.to, new_length });
			}
		}
	}

	return distances;
}