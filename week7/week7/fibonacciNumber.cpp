#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int fib(int n) {
		static vector<int> memoizator{0, 1, 1};
		if (memoizator.size() > n)
			return memoizator[n];

		int result = fib(n - 1) + fib(n - 2);
		memoizator.push_back(result);
		return result;
	}
};