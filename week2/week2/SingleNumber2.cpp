#include <vector>

using namespace std;

class Solution {
public:
	void addBits(vector<int>& bitSaver, unsigned n) {
		int index = 0;
		while (n != 0) {
			if (n & 1) {
				bitSaver[index]++;
			}
			n /= 2;
			index++;
		}
	}

	int singleNumber(vector<int>& nums) {
		vector<int> bitSaver(32, 0);

		for (auto& n : nums) {
			addBits(bitSaver, n);
		}

		int answer = 0;

		for (int i = 0; i < bitSaver.size();i++)
		{
			if (bitSaver[i] % 3 == 1)
			{
				answer |= (1 << i);
			}
		}

		return answer;
	}


};