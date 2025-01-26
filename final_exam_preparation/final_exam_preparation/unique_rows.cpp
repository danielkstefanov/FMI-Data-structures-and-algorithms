#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

void unique_rows_in_matrix_count() 
{
	int rows, cols, current_number;
	cin >> rows >> cols;


	unordered_map<long long, int> rows_info;

	for (size_t i = 0; i < rows; i++)
	{
		long long current_row_hash = 0;

		for (size_t i = 0; i < cols; i++)
		{
			cin >> current_number;
			current_row_hash *= 10;
			current_row_hash += current_number;
		}

		if (rows_info.count(current_row_hash) == 0)
			rows_info[current_row_hash] = 0;

		rows_info[current_row_hash]++;
	}

	int unique_rows_count = 0;

	for (const auto& el: rows_info)
	{
		if (el.second == 1)
			unique_rows_count++;
	}

	cout << unique_rows_count;
}