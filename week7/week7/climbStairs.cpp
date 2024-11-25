#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        static vector<int> memoizator{0, 1, 2};

        if (memoizator.size() > n)
            return memoizator[n];

        int answer = climbStairs(n - 1) + climbStairs(n - 2);
        memoizator.push_back(answer);
        return answer;
    }
};