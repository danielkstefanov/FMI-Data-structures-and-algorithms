#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0])
            return 0;

        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

        for (int i = 0; i < cols; i++) {
            if (obstacleGrid[0][i])
                break;

            matrix[0][i] = 1;
        }
        for (int i = 0; i < rows; i++) {
            if (obstacleGrid[i][0])
                break;

            matrix[i][0] = 1;
        }


        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++)
            {
                if (!obstacleGrid[i][j])
                    matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }

        return matrix[rows - 1][cols - 1];
    }
};