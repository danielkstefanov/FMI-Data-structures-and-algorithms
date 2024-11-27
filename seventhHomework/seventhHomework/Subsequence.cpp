#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

void subsequence()
{
	int N, M;
	cin >> N >> M;

	unordered_set<int> included_set;
	list<int> included;
	list<int> nonIncluded;

	for (size_t i = 1; i <= M; i++)
	{
		int current;
		cin >> current;
		included_set.insert(current);
		included.push_back(current);
	}

	for (size_t i = 1; i <= N; i++)
	{
		if (!included_set.count(i))
			nonIncluded.push_back(i);
	}

	while (included.size() && nonIncluded.size()) {

		int first = included.front();
		int second = nonIncluded.front();

		if (first < second)
		{
			cout << first << " ";
			included.pop_front();
		}
		else
		{
			cout << second << " ";
			nonIncluded.pop_front();
		}
	}

	while (included.size())
	{
		cout << included.front() << " ";
		included.pop_front();
	}


	while (nonIncluded.size())
	{
		cout << nonIncluded.front() << " ";
		nonIncluded.pop_front();
	}
}