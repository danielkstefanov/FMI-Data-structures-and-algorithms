#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        static vector<int> memoizator{0, 1, 1};

        if (memoizator.size() > n)
            return memoizator[n];

        int result = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        memoizator.push_back(result);
        return result;
    }
};