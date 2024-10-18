#include <vector>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int counting[100001]{ 0 };

        for (int i = 0; i < costs.size(); i++)
            counting[costs[i]]++;

        int iceCreamsCount = 0;
        for (int i = 1; i < 100001; i++) {
            if (counting[i] > 0) {
                if (coins >= i) {
                    coins -= i;
                    counting[i]--;
                    iceCreamsCount++;
                }
                else
                {
                    break;
                }
                i--;
            }
        }

        return iceCreamsCount;
    }
};