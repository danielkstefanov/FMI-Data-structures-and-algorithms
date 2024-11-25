#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX_TIME = 10080;

void possibleWishlistsCombinations() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	vector<int> dp(MAX_TIME + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < N; ++i) {
		for (int s = MAX_TIME; s >= A[i]; --s)
			dp[s] = (dp[s] + dp[s - A[i]]) % MOD;
	}

	long long result = 0;
	for (int s = 0; s <= MAX_TIME; ++s)
		result += dp[s];

	cout << result % MOD << endl;
}
