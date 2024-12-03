#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long getValueFromChar(char ch) {
        switch (ch) {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        }

        return 0;
    }

    long long getHash(string s) {
        long long result = 0;

        for (int i = 0; i < s.size(); i++) {
            result *= 4;
            result += getValueFromChar(s[i]);
        }

        return result;
    }

    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> result;

        if (s.size() < 10)
            return result;

        long long rollingHash = getHash(s.substr(0, 10));
        unordered_map<int, int> map;
        map[rollingHash] = 1;

        long long firstCharMultiplier = pow(4, 9);

        for (int i = 10; i < s.size(); i++) {

            rollingHash -= firstCharMultiplier * getValueFromChar(s[i - 10]);
            rollingHash *= 4;
            rollingHash += getValueFromChar(s[i]);

            if (map[rollingHash] == 1)
                result.push_back(s.substr(i - 10 + 1, 10));

            map[rollingHash] += 1;
        }

        return result;
    }
};