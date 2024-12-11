#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> degrees(n, vector<int>(2, 0));

        for (int i = 0; i < trust.size(); i++) {
            degrees[trust[i][0] - 1][0]++;
            degrees[trust[i][1] - 1][1]++;
        }

        for (int i = 0; i < n; i++) {
            if (degrees[i][0] == 0 && degrees[i][1] == n - 1)
                return i + 1;
        }

        return -1;
    }
};