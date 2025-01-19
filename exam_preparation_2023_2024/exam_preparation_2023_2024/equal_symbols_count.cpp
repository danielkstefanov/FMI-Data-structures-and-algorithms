#include <iostream>

using namespace std;

void equal_symbol_count_with_removing_one()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int queries;

	cin >> queries;

	string current_input;

	for (size_t j = 0; j < queries; j++)
	{
		cin >> current_input;
		size_t count[26]{ 0 };

		for (size_t i = 0; i < current_input.size(); i++)
			count[current_input[i] - 'a']++;

		bool is_valid = false;

		for (size_t i = 0; i < 26; i++)
		{
			bool is_current_valid = true;

			if (count[i] != 0)
			{
				count[i]--;
				int times_to_occure = -1;

				for (size_t k = 0; k < 26; k++)
				{
					if (count[k] == 0)
						continue;

					if (times_to_occure == -1)
						times_to_occure = count[k];

					if (count[k] != times_to_occure)
					{
						is_current_valid = false;
						break;
					}
				}
				count[i]++;

				if (is_current_valid == true)
				{
					is_valid = true;
					break;
				}
			}
		}

		cout << (is_valid ? 1 : 0) << '\n';
	}
}