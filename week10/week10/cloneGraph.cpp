#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    void dfs(Node* currentCloned, Node* current, unordered_map<int, Node*>& visited) {

        visited[currentCloned->val] = currentCloned;

        for (Node* neighbor : current->neighbors) {
            if (!visited.count(neighbor->val)) {
                Node* clonedNeighbor = new Node(neighbor->val);
                currentCloned->neighbors.push_back(clonedNeighbor);
                dfs(clonedNeighbor, neighbor, visited);
            }
            else
            {
                currentCloned->neighbors.push_back(visited[neighbor->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {

        if (!node)
            return nullptr;

        Node* cloned = new Node(node->val);
        unordered_map<int, Node*> visited;
        visited[cloned->val] = cloned;

        dfs(cloned, node, visited);

        return cloned;
    }
};