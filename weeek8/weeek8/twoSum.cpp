#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& weights, int kilosWanted) {
		unordered_map<int, int> weightsMap;

		for (int i = 0; i < weights.size(); i++)
		{
			int current = weights[i];
			int complement = kilosWanted - current;

			if (weightsMap.count(complement))
				return { i,weightsMap[complement] };

			weightsMap.insert({ current,i });
		}

		return { -1,-1 };
	}
};