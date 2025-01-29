#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void check_if_road_exists() {
	int nodes_count, edges_count, from, to, weight, len, end, start;
	cin >> nodes_count >> edges_count;

	unordered_map<int, unordered_map<int, int>> graph;

	for (int i = 0; i < edges_count; i++)
	{
		cin >> from >> to >> weight;
		graph[from][to] = weight;
		graph[to][from] = weight;
	}

	cin >> len;
	cin >> start;

	int result = 0;

	for (int i = 0; i < len - 1; i++)
	{
		cin >> end;
		if (graph[start].count(end))
			result += graph[start][end];

		else
		{
			result = -1;
			break;
		}

		start = end;
	}

	cout << result;
}
