#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    struct Edge {
        int to;
        double probability;
    };

    struct Node {
        int index;
        double probability;

        bool operator<(const Node& other) const {
            return probability < other.probability;
        }
    };

    double maxProbability(int n, vector<vector<int>>& edges,
        vector<double>& succProb, int start_node,
        int end_node) {

        unordered_map<int, vector<Edge>> graph;
        for (size_t i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            graph[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }

        vector<double> probabilities(n, 0);
        probabilities[start_node] = 1;

        priority_queue<Node> to_process;
        to_process.push({ start_node, 1 });

        while (!to_process.empty()) {
            Node current = to_process.top();
            to_process.pop();

            if (probabilities[current.index] > current.probability)
                continue;

            if (current.index == end_node)
                return probabilities[end_node];

            for (const Edge& current_edge : graph[current.index]) {
                double new_path_probability =
                    current.probability * current_edge.probability;

                if (probabilities[current_edge.to] < new_path_probability) {
                    probabilities[current_edge.to] = new_path_probability;
                    to_process.push({ current_edge.to, new_path_probability });
                }
            }
        }

        return probabilities[end_node];
    }
};