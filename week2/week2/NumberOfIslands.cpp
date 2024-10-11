#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void markIsland(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
            return;
        }

        if (grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '0';
        markIsland(grid, i + 1, j);
        markIsland(grid, i - 1, j);
        markIsland(grid, i, j - 1);
        markIsland(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int countOfIslands = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    markIsland(grid, i, j);
                    countOfIslands++;
                }
            }
        }

        return countOfIslands;
    }
};