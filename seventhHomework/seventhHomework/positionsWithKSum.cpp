#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;


vector<int> readCardboards(int cardboardsCount)
{
	vector<int> cardboards;

	for (int i = 1; i <= cardboardsCount; i++)
	{
		int current;
		cin >> current;
		cardboards.push_back(current);
	}

	return cardboards;
}


pair<int, int> validCardboardIndeces(int kilosWanted, const vector<int>& weights)
{
	unordered_map<int, int> weightsMap;

	for (size_t i = 0; i < weights.size(); i++)
	{
		int current = weights[i];
		int complement = kilosWanted - current;

		if (weightsMap.count(complement))
			return { i + 1,weightsMap[complement] + 1 };

		weightsMap.insert({ current,i });
	}

	return { -1,-1 };
}

void findPositions()
{
	int T;
	cin >> T;

	for (size_t i = 0; i < T; i++)
	{
		int kilosWanted, cardboardsCount;
		cin >> kilosWanted >> cardboardsCount;
		vector<int> cardboards = readCardboards(cardboardsCount);

		pair<int, int> validPositions = validCardboardIndeces(kilosWanted, cardboards);

		if (validPositions.first < validPositions.second)
			cout << validPositions.first << " " << validPositions.second << endl;
		else
			cout << validPositions.second << " " << validPositions.first << endl;

	}
}