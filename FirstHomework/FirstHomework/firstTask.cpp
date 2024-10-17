#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


size_t fromCharToIndex(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        return ch - 'a' + 10;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 36;
    }

    return 0;
}

char fromIndexToChar(size_t index)
{
    if (index >= 0 && index <= 9)
    {
        return index + '0';
    }
    else if (index >= 10 && index <= 35)
    {
        return index + 'a' - 10;
    }
    else if (index >= 36 && index <= 61)
    {
        return index + 'A' - 36;
    }

    return '$';
}


void firstTask(){
    int count[62]{ 0 };

    int N;
    cin >> N;

    string s;
    cin >> s;

    for (int i = 0; i < N;i++)
        count[fromCharToIndex(s[i])]++;

    int currentIndex = 0;

    for (int i = 0; i < 62;i++)
    {
        char ch = fromIndexToChar(i);
        for (int j = 0; j < count[i]; j++)
            s[currentIndex++] = ch;
    }

    cout << s;
}
