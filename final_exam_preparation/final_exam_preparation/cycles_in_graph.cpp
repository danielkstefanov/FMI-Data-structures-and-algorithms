#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int prim(int start, unordered_map<int, vector<Edge>>& graph, vector<bool>& visited) {
    priority_queue<Edge> pq;
    pq.push({ start, start, 0 });

    int added_edges_sum = 0;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        if (visited[current.to])
            continue;

        visited[current.to] = true;
        added_edges_sum += current.weight;

        for (auto& adj : graph[current.to]) {
            if (visited[adj.to])
                continue;

            pq.push(adj);
        }
    }

    return added_edges_sum;
}

void min_edges_in_cycles_sum() {
    int nodes_count, edges_count, from, to, weight;
    cin >> nodes_count >> edges_count;

    unordered_map<int, vector<Edge>> graph;
    long long total_edge_sum = 0;
    for (int i = 0; i < edges_count;i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back({ from, to, weight });
        graph[to].push_back({ to, from, weight });
        total_edge_sum += weight;
    }

    vector<bool> visited(nodes_count, false);

    long long result = 0;

    for (int i = 0; i < nodes_count;i++)
    {
        if (!visited[i])
            result += prim(i, graph, visited);
    }

    cout << total_edge_sum - result;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;




struct Edge
{
    int from, to, weight;

    bool operator == (const Edge& other) const 
    {
        return from == other.from && to == other.to && weight == other.weight;
    }
};

void dfs_removing_cycles(int current_node, unordered_map<int, vector<Edge>>& graph, int& remove_edges_costs, vector<bool>& visited, stack<Edge>& current_path)
{
    visited[current_node] = true;

    vector<Edge> edges(graph[current_node]);
    for (Edge edge : edges)
    {
        if (find(graph[edge.from].begin(), graph[edge.from].end(), edge) == graph[edge.from].end())
            continue;


        if (!visited[edge.to])
        {
            current_path.push(edge);
            dfs_removing_cycles(edge.to, graph, remove_edges_costs, visited, current_path);
            current_path.pop();
        }
        else
        {
            stack<Edge> copy(current_path);
            if (copy.top().from == edge.to)
                continue;

            Edge to_remove = edge;

            while (copy.size())
            {
                Edge current_edge_in_path = copy.top();
                copy.pop();

                if (current_edge_in_path.from == edge.to && to_remove.weight > current_edge_in_path.weight)
                {
                    to_remove = current_edge_in_path;
                    break;
                }
            }

            auto it = std::find(graph[to_remove.from].begin(), graph[to_remove.from].end(), to_remove);
            graph[to_remove.from].erase(it);
            to_remove = { edge.to, edge.from, edge.weight };
            it = std::find(graph[to_remove.from].begin(), graph[to_remove.from].end(), to_remove);
            graph[to_remove.from].erase(it);
         
            remove_edges_costs += to_remove.weight;
        }

    }

}

void not_optimal() {
    int nodes_count, edges_count, from, to, weight;
    cin >> nodes_count >> edges_count;

    unordered_map<int, vector<Edge>> graph;

    for (int i = 0; i < edges_count;i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back({ from, to, weight });
        graph[to].push_back({ to, from, weight });
    }

    vector<bool> visited(nodes_count, false);
    int result = 0;

    for (int i = 0; i < nodes_count;i++)
    {
        if (!visited[i])
        {
            stack<Edge> current_path;
            dfs_removing_cycles(i, graph, result, visited, current_path);
        }
    }

    cout << result;
}
