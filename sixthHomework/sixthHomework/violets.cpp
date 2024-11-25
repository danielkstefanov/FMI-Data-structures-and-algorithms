#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int MOD = 1000000007;

long violetsPermutationsCount() {
    int N;
    cin >> N;

    long long blueCount = 1;
    long long purpleCount = 1;
    long long yellowAfterBlue = 0;
    long long yellowAfterPurple = 0;


    for (int i = 1; i < N; ++i) {
        long long newCurrentBlueCount = yellowAfterPurple + purpleCount;
        long long newCurrentPurpleCount = yellowAfterBlue + blueCount;

        yellowAfterBlue = blueCount % MOD;
        yellowAfterPurple = purpleCount % MOD;
        blueCount = newCurrentBlueCount % MOD;
        purpleCount = newCurrentPurpleCount % MOD;

        if (i == N - 1)
            yellowAfterPurple = yellowAfterBlue = 0;

    }

    long long sum = blueCount + purpleCount + yellowAfterPurple + yellowAfterBlue;
    cout << (sum % MOD) << endl;
}




