#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	char getOppositeParentheses(char ch) {
		if (ch == '{')
			return '}';

		if (ch == '(')
			return ')';

		if (ch == '[')
			return ']';

		return 0;
	}

	bool isValid(string s) {
		stack<char> result;
		vector<char> validOpening = { '{', '(', '[' };
		vector<char> validClosing = { '}', ')', ']' };

		for (int i = 0; i < s.size(); i++) {
			if (find(validOpening.begin(), validOpening.end(), s[i]) !=
				validOpening.end()) {
				result.push(s[i]);
			}
			else if (find(validClosing.begin(), validClosing.end(), s[i]) !=
				validClosing.end()) {
				if (result.size() == 0 ||
					getOppositeParentheses(result.top()) != s[i]) {
					return false;
				}

				result.pop();
			}
		}

		if (!result.size()) {
			return true;
		}

		return false;
	}
};