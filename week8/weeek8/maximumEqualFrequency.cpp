#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isValidWithOneDifferent(unordered_map<int, int>& included) {
    int current = -1;
    bool isThereOnce = false;

    for (const auto& pair : included) {

        int key = pair.first;
        int value = pair.second; 

        if (current == -1 && value != 1)
            current = value;

        if (value == 1) {
            if (isThereOnce)
                return false;

            isThereOnce = true;
        }
        else if (value != current)
            return false;
    }
    return isThereOnce;
}

bool isValidWithOneMoreDifferent(unordered_map<int, int>& included) {
    unordered_map<int, int> frequency;
    for (const auto& pair : included)
        frequency[pair.second]++;
    
    if (frequency.size() > 2)
        return false; 


    if (frequency.size() == 1)
        return 1==included.size();

    auto it = frequency.begin();
    int freq1 = it->first, count1 = it->second;
    it++;
    int freq2 = it->first, count2 = it->second;

    if ((freq1 == freq2 + 1 && count1 == 1) || (freq2 == freq1 + 1 && count2 == 1))
        return true;

    if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1))
        return true;

    return false;
}

int maxEqualFreq(vector<int>& nums) {
    int longest = 0;

    unordered_map<int, int> included;

    for (int i = 0; i < nums.size(); i++) {

        if (!included.count(nums[i]))
            included.insert({ nums[i], 0 });

        included[nums[i]]++;

        if (included.size() == i + 1 || isValidWithOneDifferent(included) || isValidWithOneMoreDifferent(included))
            longest = i + 1;
    }

    return longest;
}
