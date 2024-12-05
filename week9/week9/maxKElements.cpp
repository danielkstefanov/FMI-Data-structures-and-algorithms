#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int el : nums)
            pq.push(el);

        long long maxPoints = 0;
        int current = 0;
        while (k > 0 && pq.size()) {
            current = pq.top();
            pq.pop();
            pq.push(ceil(double(current) / 3));
            maxPoints += current;
            k--;
        }

        return maxPoints;
    }
};