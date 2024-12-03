#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        char* answer = new char[nums.size() + 1];
        answer[nums.size()] = '\0';

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = nums[i][i] == '0' ? '1' : '0';
        }

        return string(answer);
    }
};