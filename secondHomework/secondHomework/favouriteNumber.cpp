#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int level = 1;

int ternarySearchByLevel(long long key, long long l, long long r)
{
    if (r != l)
    {
        long long mid1 = l + (r - l) / 3;
        long long mid2 = r - (r - l) / 3;

        if (key <= mid1)
        {
            level++;
            return ternarySearchByLevel(key, l, mid1);
        }
        else if (key >= mid2)
        {
            level++;
            return ternarySearchByLevel(key, mid2, r);
        }
        else
        {
            return level;
        }
    }
    return level;
}

void favouriteNumber()
{
    int p;
    int n;
    cin >> p >> n;
    long long numberOfFriends = pow(3, p);

    for (size_t i = 0; i < n; i++)
    {
        long long currentSearching;
        cin >> currentSearching;

        cout << ternarySearchByLevel(currentSearching, 1, numberOfFriends) << endl;
        level = 1;
    }
}