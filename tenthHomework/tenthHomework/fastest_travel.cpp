#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

struct Road {
    int to, time;
};

struct Station {
    int index, time;

    bool operator<(const Station& other) const {
        return time > other.time;
    }
};

int get_closest_upper_devider(int current_time, int bus_interval)
{
    int result = 0;

    while (result < current_time)
        result += bus_interval;

    return result;
}

vector<int> dijkstra(int start, int V, unordered_map<int, vector<Road>>& graph, vector<int> bus_intervals) {
    vector<int> times(V, INT_MAX);
    times[start] = 0;

    priority_queue<Station> nextToProcess;
    nextToProcess.push({ start, 0 });

    while (!nextToProcess.empty()) {
        auto currentNode = nextToProcess.top();
        nextToProcess.pop();

        if (currentNode.time > times[currentNode.index])
            continue;

        for (const auto& edge : graph[currentNode.index]) {
            int newTime = get_closest_upper_devider(currentNode.time, bus_intervals[currentNode.index]) + edge.time;
            if (newTime < times[edge.to]) {
                times[edge.to] = newTime;
                nextToProcess.push({ edge.to, newTime });
            }
        }
    }

    return times;
}

void fastest_travel()
{
    int V, E, s, e;
    cin >> V >> E >> s >> e;
    unordered_map<int, vector<Road>> graph;

    vector<int> bus_intervals(V, -1);
    for (size_t i = 0; i < V; i++)
        cin >> bus_intervals[i];

    int start, end, time;

    for (size_t i = 0; i < E; i++)
    {
        cin >> start >> end >> time;
        graph[start].push_back({ end,time });
    }

    cout << dijkstra(s, V, graph, bus_intervals)[e];
}