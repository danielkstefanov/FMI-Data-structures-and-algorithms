#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {

    int startIndex = 0;
    int endIndex = 0;

    stack<int> max, min;
    max.push(-1000000);
    min.push(1000000);

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] < max.top())
            max.push(nums[i]);
        else
            endIndex = i;

        if (nums[nums.size() - 1 - i] > min.top())
            min.push(nums[nums.size() - 1 - i]);
        else
            startIndex = i;
    }

    return endIndex <= startIndex ? 0 : endIndex - startIndex + 1;
}
int main()
{
    vector<int> v = { 2,6,4,8,10,9,15 };

    cout << findUnsortedSubarray(v);
}