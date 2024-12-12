#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void dfs(char current, unordered_map<char, unordered_set<char>>& graph, unordered_set<char>& visited, vector<char>& alphabet)
{
	visited.insert(current);

	for (char neighbour : graph[current])
	{
		if (!visited.count(neighbour))
			dfs(neighbour, graph, visited, alphabet);
	}

	alphabet.push_back(current);
}

void alphabetOrder() {
	unordered_map<char, unordered_set<char>> graph;
	unordered_set<char> visited;
	vector<char> alphabet;
	unordered_set<char> charactersInTheAlphabet;

	int wordsCount;
	cin >> wordsCount;
	vector<string> words(wordsCount);

	for (size_t i = 0; i < wordsCount; i++) 
	{
		cin >> words[i];
		for (char c : words[i]) {
			charactersInTheAlphabet.insert(c);
		}
	}

	string firstWord = words[0];

	for (size_t i = 1; i < wordsCount; i++)
	{
		string secondWord = words[i];

		while (firstWord.length() && secondWord.length())
		{
			if (firstWord[0] == secondWord[0])
			{
				firstWord = firstWord.substr(1);
				secondWord = secondWord.substr(1);
				continue;
			}

			graph[firstWord[0]].insert(secondWord[0]);
			break;
		}

		firstWord = words[i];
	}

	for (auto el : charactersInTheAlphabet)
	{
		if (!visited.count(el))
			dfs(el, graph, visited, alphabet);
	}

	for (long i = alphabet.size() - 1; i >= 0; i--)
		cout << alphabet[i] << " ";
}
