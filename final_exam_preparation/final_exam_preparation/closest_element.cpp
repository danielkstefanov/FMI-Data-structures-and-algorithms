#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void closest_element()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t N, x, Q;
    cin >> N;
    vector<size_t> arr(N);
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> x;
        auto right = lower_bound(arr.rbegin(), arr.rend(), x);

        if (right == arr.rend())
        {
            cout << -1 << '\n';
            continue;
        }

        if (right == arr.rbegin())
        {
            cout << (long long)*(right + 1) << '\n';
            continue;
        }
        auto left = right - 1;

        if (*right - x <= x - *left)
            cout << (long long)*(right+1) << '\n';
        else
            cout << *(left+1) << '\n';
    }
}