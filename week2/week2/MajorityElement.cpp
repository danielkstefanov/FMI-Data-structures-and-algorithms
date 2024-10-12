#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int answer = nums[0];
		int counter = 1;

		for (int i = 1; i < nums.size(); i++) {
			nums[i] == answer ? counter++ : counter--;

			if (counter == 0) 
			{
				answer = nums[i];
				counter = 1;
			}

		}

		return answer;
	}
};