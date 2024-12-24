#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

struct TwoSetEdge {
	int to, weight;
};

struct TwoSetNode {
	int index, distance;

	bool operator<(const TwoSetNode& other) const {
		return distance > other.distance;
	}
};

int dijkstra(unordered_set<int>& t_nodes, vector<int>& shortedDistancesToT, int start, int V, unordered_map<int, vector<TwoSetEdge>>& graph) {

	vector<int> distances(V, INT_MAX);
	distances[start] = 0;

	priority_queue<TwoSetNode> nextToProcess;
	nextToProcess.push({ start, 0 });

	while (!nextToProcess.empty()) {
		auto currentNode = nextToProcess.top();
		nextToProcess.pop();

		if (currentNode.distance > distances[currentNode.index])
			continue;

		if (t_nodes.count(currentNode.index))
			return currentNode.distance;

		for (const auto& edge : graph[currentNode.index]) {
			int newWeight = currentNode.distance + edge.weight;
			if (newWeight < distances[edge.to]) {
				distances[edge.to] = newWeight;
				nextToProcess.push({ edge.to, newWeight });
			}
		}
	}

	return INT_MAX;
}

void my_solution()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int nodes_count, edges_count, start, end, weight;
	cin >> nodes_count >> edges_count;

	unordered_map<int, vector<TwoSetEdge>> graph;

	for (size_t i = 0; i < edges_count; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end, weight });
		graph[end].push_back({ start, weight });
	}

	int K, t_node;
	cin >> K;

	unordered_set<int> t_nodes;

	for (size_t i = 0; i < K; i++)
	{
		cin >> t_node;
		t_nodes.insert(t_node);
	}

	int queries_count, query;
	cin >> queries_count;

	vector<int> shortedDistancesToT(nodes_count + 1, INT_MAX);
	for (int t_node : t_nodes)
		shortedDistancesToT[t_node] = 0;

	for (size_t i = 0; i < queries_count; i++)
	{
		cin >> query;

		if (shortedDistancesToT[query] == INT_MAX)
			shortedDistancesToT[query] = dijkstra(t_nodes, shortedDistancesToT, query, nodes_count, graph);

		cout << shortedDistancesToT[query] << '\n';
	}
}


//	The main difference is that in this solution we count every t_node as a starting
//	node and this way we get the shortest path from every t_node to every s_node

void better_solution()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int nodes_count, edges_count, start, end, weight;
	cin >> nodes_count >> edges_count;

	unordered_map<int, vector<TwoSetEdge>> graph;

	for (size_t i = 0; i < edges_count; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end, weight });
		graph[end].push_back({ start, weight });
	}

	int K, t_node;
	cin >> K;

	vector<int> distances(nodes_count, INT_MAX);
	priority_queue<TwoSetNode> nextToProcess;

	for (size_t i = 0; i < K; i++)
	{
		cin >> t_node;
		distances[t_node] = 0;
		nextToProcess.push({ t_node,0 });
	}

	while (!nextToProcess.empty()) {
		auto currentNode = nextToProcess.top();
		nextToProcess.pop();

		if (currentNode.distance > distances[currentNode.index])
			continue;

		for (const auto& edge : graph[currentNode.index]) {
			int newWeight = currentNode.distance + edge.weight;
			if (newWeight < distances[edge.to]) {
				distances[edge.to] = newWeight;
				nextToProcess.push({ edge.to, newWeight });
			}
		}
	}

	int queries_count, query;
	cin >> queries_count;
	for (size_t i = 0; i < queries_count; i++)
	{
		cin >> query;
		cout << distances[query] << '\n';
	}
}