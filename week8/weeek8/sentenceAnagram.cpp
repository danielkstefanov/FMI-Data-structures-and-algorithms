#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

void isAnagramFirstSolution() {

	int N;
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		unordered_map<string, int> firstWords;

		int firstWordsCount, secondWordsCount;
		cin >> firstWordsCount >> secondWordsCount;

		string currentWord;

		for (size_t k = 0; k < firstWordsCount; k++)
		{
			cin >> currentWord;
			firstWords[currentWord]++;
		}

		bool isValid = true;

		for (size_t k = 0; k < secondWordsCount; k++)
		{
			cin >> currentWord;
			if (firstWords[currentWord] == 0)
			{
				isValid = false;
			}
			else 
			{
				firstWords[currentWord]--;
			}
		}

		cout << (isValid ? "Yes\n" : "No\n");
	}

}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;


long long getHash(const string& word)
{
    long long hash = 0;

    for (char el : word)
    {
        hash *= 26;
        hash += el;
    }

    return hash;
}

void isAnagramSecondSolution() {

    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        unordered_map<long long, int> firstWords;

        int firstWordsCount, secondWordsCount;
        cin >> firstWordsCount >> secondWordsCount;

        string currentWord;

        for (size_t k = 0; k < firstWordsCount; k++)
        {
            cin >> currentWord;
            long long hash = getHash(currentWord);
            firstWords[hash]++;
        }

        bool isValid = true;

        for (size_t k = 0; k < secondWordsCount; k++)
        {
            cin >> currentWord;
            long long hash = getHash(currentWord);
            if (firstWords[hash] == 0)
            {
                isValid = false;
            }
            else
            {
                firstWords[hash]--;
            }
        }

        cout << (isValid ? "Yes\n" : "No\n");
    }

}