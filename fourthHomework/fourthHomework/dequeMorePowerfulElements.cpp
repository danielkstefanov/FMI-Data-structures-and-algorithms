#include <iostream>
#include <stack>
#include <deque>

using namespace std;


void clearAndPrintDeque(deque<int>& nums)
{
	while (nums.size() > 0)
	{
		cout << nums.front() << ' ';
		nums.pop_front();
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);




	int N;
	cin >> N;

	deque<int> positives;

	bool wasLastAddedPositive = false;

	for (size_t i = 0; i < N; i++)
	{
		int current;
		cin >> current;

		if (current > 0)
		{
			positives.push_back(current);
			wasLastAddedPositive = true;
		}
		else {
			if (!wasLastAddedPositive)
			{
				cout << current << ' ';
				continue;
			}

			bool toSet = false;

			current = -current;

			if (wasLastAddedPositive)
			{
				while (positives.size() > 0)
				{
					if (current > positives.back())
					{
						positives.pop_back();
					}
					else if (current == positives.back())
					{
						toSet = true;
						positives.pop_back();
						break;
					}
					else
					{
						toSet = true;
						break;
					}
				}
			}

			if (positives.size() == 0 && !toSet)
				cout << -current << ' ';

			wasLastAddedPositive = toSet;
		}
	}

	clearAndPrintDeque(positives);
}