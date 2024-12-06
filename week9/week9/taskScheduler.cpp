#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    struct Task {
        int minTime;
        bool operator<(const Task& rhs) const { return minTime > rhs.minTime; }
    };

    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<Task> pq;
        int minTimes[26]{ 0 };
        for (auto task : tasks) {
            pq.push({ minTimes[task - 'A'] });
            minTimes[task - 'A'] += (n + 1);
        }
        int currentTime = 0;

        while (pq.size()) {
            if (currentTime < pq.top().minTime) {
                currentTime = pq.top().minTime;
            }

            pq.pop();
            currentTime++;
        }

        return currentTime;
    }
};