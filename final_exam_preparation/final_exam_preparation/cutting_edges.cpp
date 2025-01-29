#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

int dfs(int current, unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited, int& result)
{
    visited[current] = true;

    int nodes_count = 1;

    for (int el : graph[current])
    {
        if (!visited[el])
        {
            nodes_count += dfs(el, graph, visited, result);
        }
    }

    if (nodes_count % 2 == 0)
        result++;

    return nodes_count;
}

void cutting_edges() {
    int nodes_count, edges_count, from, to;
    cin >> nodes_count >> edges_count;

    unordered_map<int, unordered_set<int>> graph;

    for (int i = 0; i < edges_count; i++)
    {
        cin >> from >> to;
        graph[from].insert(to);
        graph[to].insert(from);
    }

    int result = 0;
    vector<bool> visited(nodes_count+1, false);
    dfs(1, graph, visited, result);

    cout << result-1;
}
