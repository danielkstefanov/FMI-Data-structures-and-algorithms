#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int destination = 0;

    void dfs(int current, vector<vector<int>>& graph,
        vector<int>& path, vector<vector<int>>& answer) {

        path.push_back(current);

        if (current == destination)
            answer.push_back(path);

        for (int neighbor : graph[current])
            dfs(neighbor, graph, path, answer);

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        destination = graph.size() - 1;
        vector<vector<int>> answer;
        vector<int> path;

        dfs(0, graph, path, answer);

        return answer;
    }
};