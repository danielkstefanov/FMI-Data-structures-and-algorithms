#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int bfs(int start_node, unordered_map<int, unordered_set<int>>& graph)
{
    int children_sum = 0;
    unordered_set<int> visited;
    visited.insert(start_node);

    queue<int> current_level;
    current_level.push(start_node);

    while (current_level.size())
    {
        int current_level_size = current_level.size();

        for (int i = 0; i < current_level_size; i++)
        {
            int current_node = current_level.front();
            current_level.pop();

            for (int neighbour : graph[current_node])
            {
                if (visited.count(neighbour))
                    continue;

                children_sum += neighbour;
                visited.insert(neighbour);
                current_level.push(neighbour);
            }

        }
    }

    return children_sum;
}


void childrens_sum() {

    int edges_count, queries_count, current_query, from, to;
    cin >> edges_count >> queries_count;

    unordered_map<int, unordered_set<int>> graph;

    for (int i = 0; i < edges_count; i++)
    {
        cin >> from >> to;
        graph[from].insert(to);
    }

    for (int i = 0; i < queries_count; i++)
    {
        cin >> current_query;
        cout << bfs(current_query, graph) << '\n';
    }
}
