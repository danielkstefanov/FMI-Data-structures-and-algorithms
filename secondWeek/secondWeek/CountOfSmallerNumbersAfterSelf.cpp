#include <vector>
#include <iostream>

using namespace std;

void mergeWithCounting(vector<pair<int, int>>& pairs, vector<int>& counts,
    int start, int mid, int end) {
    vector<pair<int, int>> temp(end - start + 1);

    int left = start;
    int right = mid + 1;
    int currentIndex = 0;

    int rightCounter = 0;

    while (left <= mid && right <= end) {
        if (pairs[left].first <= pairs[right].first) {
            counts[pairs[left].second] += rightCounter;
            temp[currentIndex++] = pairs[left++];
        }
        else {
            temp[currentIndex++] = pairs[right++];
            rightCounter++;
        }
    }

    while (left <= mid)
    {
        counts[pairs[left].second] += rightCounter;
        temp[currentIndex++] = pairs[left++];
    }

    while (right <= end)
        temp[currentIndex++] = pairs[right++];

    for (int i = 0; i < temp.size(); i++)
        pairs[start + i] = temp[i];
}

void mergeSortWithCounting(vector<pair<int, int>>& pairs,
    vector<int>& count, int start, int end) {
    if (start < end) {
        int mid = (end + start) / 2;
        mergeSortWithCounting(pairs, count, start, mid);
        mergeSortWithCounting(pairs, count, mid + 1, end);
        mergeWithCounting(pairs, count, start, mid,end);
    }
}

vector<int> countSmaller(vector<int>& nums) {
    vector<pair<int, int>> pairs;
    vector<int> counts(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
        pairs.push_back({ nums[i], i });

    mergeSortWithCounting(pairs, counts, 0, nums.size() - 1);

    for (int i = 0;i < nums.size();i++)
        cout << counts[i] << ' ';

    return counts;
}

int main()
{
    vector<int> arr{5, 2, 6, 1};
    countSmaller(arr);
}