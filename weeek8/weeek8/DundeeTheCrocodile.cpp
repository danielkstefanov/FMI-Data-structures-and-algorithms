#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

void dundeeTheCrocodile() 
{
	unordered_map<string, int> words_map;
	
	string firstRow, secondRow;
	getline(cin, firstRow);
	getline(cin, secondRow);

	string concatenatedRows = firstRow+ " " + secondRow;

	stringstream words(concatenatedRows);
	string currentWord;

	while (words >> currentWord)
		words_map[currentWord]++;

	vector<string> answer;

	for (auto s: words_map)
	{
		if (s.second == 1)
			answer.push_back(s.first);
	}

	sort(answer.begin(), answer.end());

	for (size_t i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

}