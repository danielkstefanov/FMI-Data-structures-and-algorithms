#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool intersects(vector<int> a, vector<int> b) { return a[1] >= b[0]; }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        vector<int> currentInterval = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (intersects(currentInterval, intervals[i])) {
                currentInterval[1] = max(intervals[i][1], currentInterval[1]);
            }
            else {
                answer.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }

        answer.push_back(currentInterval);

        return answer;
    }
};