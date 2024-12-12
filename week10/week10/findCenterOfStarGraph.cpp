#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> nodes;

        for (int i = 0; i < edges.size(); i++) {

            if (!nodes.count(edges[i][0]))
                nodes.insert(edges[i][0]);
            else
                return edges[i][0];


            if (!nodes.count(edges[i][1]))
                nodes.insert(edges[i][1]);
            else
                return edges[i][1];
        }

        return -1;
    }
};


class Solution2 {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> nodesDegrees;

        for (int i = 0; i < edges.size(); i++) {
            if (!nodesDegrees.count(edges[i][0]))
                nodesDegrees[edges[i][0]] = 1;

            if (!nodesDegrees.count(edges[i][1]))
                nodesDegrees[edges[i][1]] = 1;

            nodesDegrees[edges[i][0]] += 1;
            nodesDegrees[edges[i][1]] += 1;
        }

        for (pair<int, int> el : nodesDegrees)
            if (el.second == nodesDegrees.size())
                return el.first;

        return -1;
    }
};