#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void dfs(vector<char>& visited, unordered_map<int, unordered_set<int>>& graph, bool& has_cycle ,int current, int parent) {
	visited[current] = 'o';

	for (int neighbour : graph[current]) {
		if (visited[neighbour] == 'c')
			continue;
		else if (visited[neighbour] == 'o' && neighbour != parent)
			has_cycle = true;
		
		if(neighbour != parent && visited[neighbour] == 'u')
			dfs(visited, graph, has_cycle, neighbour, current);
	}

	visited[current] = 'c';
}

int cycle_count(int nodes_count, unordered_map<int, unordered_set<int>>& graph)
{
	vector<char> visited(nodes_count, 'u');
	int count = 0;

	for (size_t i = 0; i < nodes_count; i++)
	{
		if (visited[i] != 'u')
			continue;

		bool has_cycle = false;
		dfs(visited, graph, has_cycle, i, i);
		if (has_cycle)
			count++;
	}

	return count;
}

void components_with_cycles_count()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int queries, nodes_count, edges_count, from,to;
    cin >> queries;

    for (size_t i = 0; i < queries; i++)
    {
        cin >> nodes_count >> edges_count;

        unordered_map<int, unordered_set<int>> graph;

        for (size_t i = 0; i < edges_count; i++)
        {
            cin >> from >> to;
			graph[from].insert(to);
			graph[to].insert(from);
        }

		cout << cycle_count(nodes_count,graph) << '\n';
    }
}