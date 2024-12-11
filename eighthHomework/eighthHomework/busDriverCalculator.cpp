#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Group
{
    int peopleCount;
    int gettingOn;
    int gettingOff;

    Group(int peopleCount, int gettingOn, int gettingOff) 
    {
        this->peopleCount= peopleCount;
        this->gettingOn = gettingOn;
        this->gettingOff = gettingOff;
    }
};

struct groupMinGettingOn 
{
    bool operator() (const Group& lhs, const Group& rhs)
    {
        return lhs.gettingOn > rhs.gettingOn;
    }
};

struct groupMinGettingOff
{
    bool operator() (const Group& lhs, const Group& rhs)
    {
        return lhs.gettingOff > rhs.gettingOff;
    }
};

int main() {
    int requests;
    cin >> requests;

    for (size_t i = 0; i < requests; i++)
    {
        int groupsCount, busCapacity;
        cin >> groupsCount >> busCapacity;

        priority_queue<Group, vector<Group>, groupMinGettingOn> toGetOn;
        priority_queue<Group, vector<Group>, groupMinGettingOff> inBus;

        int currentCapacity = 0;
        bool canTakeAll = true;

        for (size_t i = 0; i < groupsCount; i++)
        {
            int groupCount, gettingOn, gettingOff;
            cin >> groupCount >> gettingOn >> gettingOff;
        
            toGetOn.push(Group(groupCount, gettingOn, gettingOff));
        }


        while (toGetOn.size())
        {
            Group currentToGetOn = toGetOn.top();
            toGetOn.pop();

            while (inBus.size() && inBus.top().gettingOff <= currentToGetOn.gettingOn)
            {
                Group currentToGetOff = inBus.top();
                inBus.pop();
                currentCapacity -= currentToGetOff.peopleCount;
            }

            if (currentCapacity + currentToGetOn.peopleCount > busCapacity)
            {
                canTakeAll = false;
                break;
            }

            currentCapacity += currentToGetOn.peopleCount;
            inBus.push(currentToGetOn);
        }


		cout << (canTakeAll ? 1 : 0) << '\n';
    }
}