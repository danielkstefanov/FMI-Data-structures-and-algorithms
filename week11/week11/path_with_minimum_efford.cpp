#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct Node {
        int x;
        int y;
        int efford;

        bool operator<(const Node& other) const { return efford > other.efford; }
    };

    vector<vector<int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    bool are_valid_coordinates(int new_x, int new_y, int m, int n) {
        return new_x >= 0 && new_x < m && new_y >= 0 && new_y < n;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effords(m, vector<int>(n, INT_MAX));
        effords[0][0] = 0;

        priority_queue<Node> pq;
        pq.push({ 0, 0, 0 });

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            if (current.efford > effords[current.x][current.y])
                continue;

            if (current.x == m - 1 && current.y == n - 1)
                return current.efford;

            for (int i = 0; i < 4; i++) {
                int new_x = current.x + directions[i][0];
                int new_y = current.y + directions[i][1];

                if (!are_valid_coordinates(new_x, new_y, m, n))
                    continue;

                int new_efford =
                    max(current.efford,
                        abs(heights[new_x][new_y] - heights[current.x][current.y]));

                if (new_efford < effords[new_x][new_y]) {
                    effords[new_x][new_y] = new_efford;
                    pq.push({ new_x, new_y, new_efford });
                }
            }
        }

        return effords[m - 1][n - 1];
    }
};