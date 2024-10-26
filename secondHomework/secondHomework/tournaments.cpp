#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int studentsCount;
	int tournamentsCount;
	cin >> studentsCount >> tournamentsCount;

	vector<int> v(studentsCount);

	for (size_t i = 0; i < studentsCount; i++)
		cin >> v[i];

	std::sort(v.begin(), v.end());

	int lower, upper;

	for (size_t i = 0; i < tournamentsCount; i++)
	{
		cin >> lower >> upper;

		auto lowerIter = std::lower_bound(v.begin(), v.end(), lower);
		auto upperIter = std::upper_bound(v.begin(), v.end(), upper);

		cout << max(0, int(upperIter - lowerIter)) << endl;
	}
}
