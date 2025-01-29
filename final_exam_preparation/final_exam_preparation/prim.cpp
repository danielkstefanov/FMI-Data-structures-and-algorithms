#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Greedy algorithm
// Time complexity O(E*logE)

struct Edge
{
	int from, to, weight;
};

vector<Edge> prim(int nodes_count, int start_node, unordered_map<int, vector<Edge>> graph)
{
	vector<Edge> edges;
	unordered_set<int> visited;
	visited.insert(start_node);

	priority_queue<Edge> pq;
	pq.push({ start_node,start_node,0 });

	while (!pq.empty() && visited.size() < nodes_count)
	{
		Edge current = pq.top();
		pq.pop();

		if (visited.count(current.to))
			continue;

		edges.push_back(current);
		visited.insert(current.to);

		for (Edge edge: graph[current.to])
		{
			if (visited.count(edge.to))
				continue;

			pq.push(edge);
		}

	}

	return edges;
}