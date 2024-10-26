#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int l = 0;
        int r = matrix.size() * matrix[0].size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int currentRow = floor(mid / matrix[0].size());
            int currentCol = mid - currentRow * matrix[0].size();

            if (matrix[currentRow][currentCol] == target)
                return true;
            else if (matrix[currentRow][currentCol] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};