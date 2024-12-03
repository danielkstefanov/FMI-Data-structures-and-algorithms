#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> answer;

        for (int i = 0; i < candyType.size(); i++) {
            answer.insert(candyType[i]);
        }

        int max = candyType.size() / 2;

        return answer.size() > max ? max : answer.size();
    }
};