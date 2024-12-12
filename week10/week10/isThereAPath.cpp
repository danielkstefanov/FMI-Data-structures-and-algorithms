#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class SolutionWithDFS {
public:
    int startingVertex = 0;
    int endVertex = 0;

    bool dfs(int current, unordered_set<int>& visited,
        unordered_map<int, unordered_set<int>>& graph) {    

        visited.insert(current);

        for (int neighbor : graph[current]) {

            if (neighbor == endVertex)
                return true;

            if (!visited.count(neighbor)) {
                if (dfs(neighbor, visited, graph))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
        int destination) {

        if (source == destination)
            return true;

        unordered_map<int, unordered_set<int>> graph;

        for (size_t i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }
        unordered_set<int> visited;
        startingVertex = source;
        endVertex = destination;
        return dfs(source, visited, graph);
    }
};

class SolutionWithBFS {
public:
    bool bfs(int starting_vertex, int end_vertex,
        unordered_map<int, unordered_set<int>>& graph) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(starting_vertex);
        visited.insert(starting_vertex);

        while (!q.empty()) {
            int level_size = q.size();

            for (int i = 0; i < level_size; ++i) {
                int current = q.front();
                q.pop();

                for (int neighbor : graph[current]) {

                    if (neighbor == end_vertex)
                        return true;
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
        int destination) {

        if (source == destination)
            return true;

        unordered_map<int, unordered_set<int>> graph;

        for (size_t i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }

        return bfs(source, destination, graph);
    }
};