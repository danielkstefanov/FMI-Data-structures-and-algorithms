#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MOD = 1e9 + 7;

struct Edge {
	int to, weight;
};

struct Node {
	int index;
	long long distance;

	bool operator<(const Node& other) const {
		return distance > other.distance;
	}
};

void shortest_paths()
{
	int N, M;
	cin >> N >> M;

	vector<vector<Edge>> graph(N + 1, vector<Edge>());

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	priority_queue<Node> pq;
	pq.push({ 1,0 });

	vector<long long> distances(N + 1, LLONG_MAX);
	vector<long long> ways(N + 1, 0);

	distances[1] = 0;
	ways[1] = 1;

	while (!pq.empty())
	{
		Node current = pq.top();
		pq.pop();

		if (current.distance > distances[current.index])
			continue;

		for (const Edge& current_edge : graph[current.index])
		{
			int new_distance = distances[current.index] + current_edge.weight;

			if (distances[current_edge.to] > new_distance)
			{
				distances[current_edge.to] = new_distance;
				ways[current_edge.to] = ways[current.index];
				pq.push({ current_edge.to, new_distance });
			}
			else if (distances[current_edge.to] == new_distance)
			{
				ways[current_edge.to] = (ways[current_edge.to] + ways[current.index]) % MOD;
			}
		}
	}

	cout << (distances[N] == LLONG_MAX ? -1 : distances[N]) << " " << ways[N];
}