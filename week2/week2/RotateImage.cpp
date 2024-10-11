#include <vector>

using namespace std;

class Solution {
public:
    void rotateOnLayer(int layer, vector<vector<int>>& matrix) {
        int saved = matrix[layer][layer];
        int nextX = layer + 1;
        int nextY = layer;
        int currentX = layer;
        int currentY = layer;
        // 0 - down      1-right      2 -up        3-left
        int direction = 0;
        int sizeOfTheSubmatrix = matrix.size() - (layer * 2);

        while (!(nextX == layer && nextY == layer)) {
            matrix[currentX][currentY] = matrix[nextX][nextY];

            currentX = nextX;
            currentY = nextY;

            if ((currentX - layer == 0 &&
                currentY - layer == sizeOfTheSubmatrix - 1) ||
                (currentX - layer == sizeOfTheSubmatrix - 1 &&
                    currentY - layer == 0) ||
                (currentX - layer == sizeOfTheSubmatrix - 1 &&
                    currentY - layer == sizeOfTheSubmatrix - 1)) {
                direction++;
            }

            if (direction == 0) {
                nextX = currentX + 1;
            }
            else if (direction == 1) {
                nextY = currentY + 1;
            }
            else if (direction == 2) {
                nextX = currentX - 1;
            }
            else if (direction == 3) {
                nextY = currentY - 1;
            }
        }

        matrix[currentX][currentY] = saved;
    }

    void rotate(vector<vector<int>>& matrix) {

        for (int i = 0; i < matrix.size() / 2; i++) {

            int rotations = (matrix.size() - (i * 2)) - 1;
            for (int j = 0; j < rotations; j++) {
                rotateOnLayer(i, matrix);
            }
        }
    }
};