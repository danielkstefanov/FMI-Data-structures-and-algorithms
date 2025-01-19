#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int to, weight;

    Edge(int to, int weight) : to(to), weight(weight) {}

    bool operator < (const Edge& other) const 
    {
        return weight > other.weight;
    }
};


long long prim(int start, unordered_map<int, vector<Edge>>& graph, int& nodes_in_component_count, vector<bool>& visited) 
{
    priority_queue<Edge> pq;
    pq.push({ start, 0 });
    long long res = 0;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        if (visited[current.to])
            continue;

        visited[current.to] = true;
        nodes_in_component_count++;
        res += current.weight;

        for (auto& adj : graph[current.to]) {
            if (visited[adj.to])
                continue;

            pq.push(adj);
        }
    }

    return res;
}


void msp_weights()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int graphs_count, nodes_count, edges_count, k, from, to, weight;
    cin >> graphs_count;

    for (size_t i = 0; i < graphs_count; i++)
    {
        cin >> nodes_count >> edges_count >> k;
        long long current_res = 0;

        unordered_map<int, vector<Edge>> graph;

        for (size_t j = 0; j < edges_count; j++)
        {
            cin >> from >> to >> weight;

            graph[from].push_back({ to, weight });
            graph[to].push_back({ from, weight });
        }

        vector<bool> visited(nodes_count, false);

        for (size_t j = 0; j < nodes_count; j++)
        {
            if (!visited[j]) 
            {
                int nodes_in_components_count = 0;
                long long weight_sum_mst = prim(j, graph, nodes_in_components_count, visited);
                if (nodes_in_components_count % k == 0)
                    current_res += weight_sum_mst;
            }
        }

        cout << current_res << '\n';
    }

}