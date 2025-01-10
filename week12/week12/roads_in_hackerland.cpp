#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

struct MyEdge {
	int from;
	int to;
	int weight;

	bool operator<(const MyEdge& other) const {
		return weight > other.weight;
	}
};

vector<MyEdge> prim(int n, int start, unordered_map<int, vector<MyEdge>>& graph) {
	priority_queue<MyEdge> pq;
	unordered_set<int> visited;
	pq.push({ start, start, 0 });

	vector<MyEdge> mstEdges;

	while (!pq.empty() && visited.size() < n) {
		auto current = pq.top();
		pq.pop();
		if (visited.count(current.to)) {
			continue;
		}

		visited.insert(current.to);
		mstEdges.push_back(current);
		for (auto& adj : graph[current.to]) {
			if (visited.count(adj.to)) {
				continue;
			}
			pq.push(adj);
		}
	}

	return mstEdges;
}

string from_decimal_to_binary(long long number) 
{
	if (number == 0)
		return "0";

	string binaryString;
	while (number > 0) {
		binaryString.push_back('0' + (number % 2));
		number /= 2;
	}

	reverse(binaryString.begin(), binaryString.end());
	return binaryString;
}

void dfs(long long& total_sum, int& start,int current, unordered_set<int>& visited, unordered_map<int, vector<MyEdge>>& graph, int current_path_length) {
    visited.insert(current);
	if(current > start)
		total_sum += current_path_length;


	for (int i = 0; i < graph[current].size(); i++) {
		int current_neightbour = graph[current][i].to;
        if (!visited.count(current_neightbour)) {
            dfs(total_sum,start, current_neightbour, visited, graph, current_path_length + graph[current][i].weight);
        }
    }
}


string roadsInHackerland(int n, vector<vector<int>> roads) 
{
	int from, to, weight;

	unordered_map<int, vector<MyEdge>> graph;

	for (size_t i = 0; i < roads.size(); i++)
	{
		from = roads[i][0];
		to = roads[i][1];
		weight = roads[i][2];
		weight = pow(2, weight);
		graph[from].push_back({ from, to, weight });
		graph[to].push_back({ to, from, weight });
	}

	vector<MyEdge> mst_edges = prim(n, 1, graph);
	unordered_map<int, vector<MyEdge>> mst;


	for (size_t i = 1; i < mst_edges.size(); i++)
	{
		mst[mst_edges[i].from].push_back({ mst_edges[i].from, mst_edges[i].to, mst_edges[i].weight });
		mst[mst_edges[i].to].push_back({ mst_edges[i].to, mst_edges[i].from, mst_edges[i].weight });
	}

	long long total_sum = 0;
	for (int i = 1; i <= n; i++)
	{
		unordered_set<int> visited;
		int len = 0;
		dfs(total_sum, i, i, visited, mst, len);
	}


	return from_decimal_to_binary(total_sum);
}
//
//int main()
//{
//	int cities_count, roads_count, from, to, weight;
//	cin >> cities_count >> roads_count;
//
//	unordered_map<int, vector<MyEdge>> graph;
//
//	for (size_t i = 0; i < roads_count; i++)
//	{
//		cin >> from >> to >> weight;
//		weight = pow(2, weight);
//		graph[from].push_back({ from, to, weight });
//		graph[to].push_back({ to, from, weight });
//	}
//
//	vector<MyEdge> mst_edges = prim(cities_count, 1, graph);
//	unordered_map<int, vector<MyEdge>> mst;
//
//	
//	for (size_t i = 1; i < mst_edges.size(); i++)
//	{
//		mst[mst_edges[i].from].push_back({ mst_edges[i].from, mst_edges[i].to, mst_edges[i].weight });
//		mst[mst_edges[i].to].push_back({ mst_edges[i].to, mst_edges[i].from, mst_edges[i].weight });
//	}
//
//	long long total_sum = 0;
//	for (int i = 1; i <= cities_count; i++) 
//	{
//		unordered_set<int> visited;
//		int len = 0;
//		dfs(total_sum,i, i, visited, mst, len);
//	}
//
//	 
//	cout << from_decimal_to_binary(total_sum);
//}
//
//
//
