#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> result;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                result.push(s[i]);
            }
            else {
                result.pop();
            }
        }

        s.resize(result.size());

        while (result.size()) {
            s[result.size() - 1] = result.top();
            result.pop();
        }

        return s;
    }
};