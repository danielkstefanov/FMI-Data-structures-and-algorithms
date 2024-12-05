#include <vector>
#include <queue>
#include <string>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k = 0;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int el : nums)
            pq.push(el);

        while (pq.size() > k)
            pq.pop();
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};