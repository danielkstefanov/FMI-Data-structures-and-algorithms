#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        vector<pair<int, int>> numsPairs;

        for (int i = 0; i < nums.size(); i++) {
            numsPairs.push_back({ nums[i],i });
        }

        sort(numsPairs.begin(), numsPairs.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (numsPairs[i].first == numsPairs[i + 1].first &&
                abs(numsPairs[i].second - numsPairs[i + 1].second) <= k)
                return true;
        }

        return false;
    }
};