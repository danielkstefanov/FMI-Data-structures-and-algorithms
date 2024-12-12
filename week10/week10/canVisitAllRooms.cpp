#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class SolutionWithBFS {
public:
    bool bfs(int starting_vertex, int rooms_count,
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
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        return visited.size() == rooms_count;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, unordered_set<int>> graph;

        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++)
                graph[i].insert(rooms[i][j]);
        }

        return bfs(0, rooms.size(), graph);
    }
};

class SolutionWithDFS {
public:
    void dfs(int current, unordered_set<int>& visited,
        unordered_map<int, unordered_set<int>>& graph) {
        visited.insert(current);

        for (int neighbor : graph[current]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor, visited, graph);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, unordered_set<int>> graph;

        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++)
                graph[i].insert(rooms[i][j]);
        }

        unordered_set<int> visited;

        dfs(0, visited, graph);
        return visited.size() == rooms.size();
    }
};