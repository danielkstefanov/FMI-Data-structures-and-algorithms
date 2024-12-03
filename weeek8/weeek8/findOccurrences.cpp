#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
        int x) {
        int occurence = 1;
        unordered_map<int, int> positionsWithIndeces;
        size_t numsCount = nums.size();
        size_t queriesCount = queries.size();

        for (int i = 0; i < numsCount; ++i) {
            if (nums[i] == x)
                positionsWithIndeces.insert({ occurence++, i + 1 });
        }

        vector<int> result;

        for (int i = 0; i < queriesCount; ++i) {
            auto current = positionsWithIndeces.find(queries[i]);
            result.push_back(current != positionsWithIndeces.end()
                ? current->second - 1
                : -1);
        }

        return result;
    }
};