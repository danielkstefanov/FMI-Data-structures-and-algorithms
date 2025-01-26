#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void brothers_fight()
{
	int days_count;
	cin >> days_count;

	unordered_map<int, int> stickers;

	vector<int> stickers_by_days(days_count);
	for (size_t i = 0; i < days_count; i++)
		cin >> stickers_by_days[i];

	vector<int> wanted_stickers(days_count);
	for (size_t i = 0; i < days_count; i++)
		cin >> wanted_stickers[i];

	int days_with_fight = 0;
	
	for (size_t i = 0; i < days_count; i++)
	{
		int inserted = stickers_by_days[i];
		int wanted = wanted_stickers[i];

		if (stickers.count(inserted) == 0)
			stickers.insert({ inserted,0});

		stickers[inserted]++;

		if (stickers.count(wanted) == 0 || stickers[wanted] == 0)
			days_with_fight++;
		else 
			stickers[wanted]--;
	}

	cout << days_with_fight;
}