#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

const int INF = -1;

std::unordered_map<int, std::unordered_map<int, int>> graph;

void printSolution(const std::vector<int>& results, const int start, const int V)
{
    for (int v = 1; v <= V; v++)
    {
        if (v == start)
            continue;

        int distance = results[v] != INF ? results[v] : -1;
        std::cout << distance << " ";
    }
    std::cout << "\n";
}

void solve(const int start, const int V)
{
    std::vector<int> results(V + 1, INF);
    results[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, start));

    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();

        int currentDistance, v;
        currentDistance = current.first;
        v = current.second;

        if (results[v] < currentDistance)
            continue;

        for (auto it = graph[v].cbegin(); it != graph[v].cend(); it++)
        {
            int u, vertexDistance;
            u = it->first;
            vertexDistance = it->second;

            if (results[u] == INF || currentDistance + vertexDistance < results[u])
            {
                results[u] = currentDistance + vertexDistance;
                pq.push(std::make_pair(results[u], u));
            }
        }
    }

    printSolution(results, start, V);
}

void dijkstra()
{
    int Q;
    std::cin >> Q;

    while (Q--)
    {
        int V, E;
        std::cin >> V >> E;

        for (int i = 1; i <= V; i++)
            graph[i];

        int v, u, w;
        for (int i = 0; i < E; i++)
        {
            std::cin >> v >> u >> w;

            if (graph[v].count(u) && graph[v][u] <= w)
                continue;

            graph[v][u] = w;
            graph[u][v] = w;
        }

        int start;
        std::cin >> start;

        solve(start, V);

        graph.clear();
    }
}
