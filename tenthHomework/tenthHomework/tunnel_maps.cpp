#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

struct Tunnel {
	int to;
	long long time;
	int kilos;
};

struct Intersection {
	int index;
	long long time;
	int kilos;

	bool operator<(const Intersection& other) const {
		return kilos > other.kilos;
	}
};

int dijkstra(int start, int V, unordered_map<int, vector<Tunnel>>& graph, int battery_time) {
	vector<int> kilos(V + 1, INT_MAX);
	kilos[start] = 0;

	priority_queue<Intersection> nextToProcess;
	nextToProcess.push({ start, 0, 0 });

	while (!nextToProcess.empty()) {
		auto currentNode = nextToProcess.top();
		nextToProcess.pop();

		if (currentNode.index == V)
			return kilos[V];

		for (const auto& edge : graph[currentNode.index]) {
			int newKilos = max(currentNode.kilos, edge.kilos);
			long long newTime = currentNode.time + edge.time;

			if (newTime <= battery_time) {
				kilos[edge.to] = newKilos;
				nextToProcess.push({ edge.to,newTime ,newKilos });
			}
		}
	}

	return kilos[V];
}


void tunnel_maps()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int intersections_count, tunnels_count, battery_time;
	cin >> intersections_count >> tunnels_count >> battery_time;

	unordered_map<int, vector<Tunnel>> graph;

	int start, end, kilos, time;
	for (size_t i = 0; i < tunnels_count; i++)
	{
		cin >> start >> end >> kilos >> time;
		graph[start].push_back({ end,time,kilos });
	}

	int res = dijkstra(1, intersections_count, graph, battery_time);
	cout << (res == INT_MAX ? -1 : res);
}