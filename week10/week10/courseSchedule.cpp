#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void dfs(bool& hasCycle, int current, vector<int>& result,
        vector<char>& visited,
        unordered_map<int, unordered_set<int>>& graph) {

        visited[current] = 'o';

        for (int neighbour : graph[current]) {

            if (visited[neighbour] == 'o') {
                hasCycle = true;
                return;
            }
            else if (visited[neighbour] == 'c') {
                continue;
            }
            else {
                dfs(hasCycle, neighbour, result, visited, graph);
            }
        }

        visited[current] = 'c';
        result.push_back(current);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        vector<char> visited(numCourses + 1, 'u');

        for (int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i][0]].insert(prerequisites[i][1]);

        vector<int> result;
        bool hasCycle = false;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 'u')
                dfs(hasCycle, i, result, visited, graph);
        }
        return hasCycle ? vector<int>() : result;
    }
};