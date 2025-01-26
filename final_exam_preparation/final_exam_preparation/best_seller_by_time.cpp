#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Sale
{
	int product_id;
	int time;
};

struct MinTimeSellComparator
{
	bool operator() (const Sale& lhs, const Sale& rhs) const
	{
		return lhs.time > rhs.time;
	}
};


int main()
{
	int sells_count, current_product_id, sell_time;
	cin >> sells_count;

	priority_queue <Sale, vector<Sale>, MinTimeSellComparator> to_sell;

	for (size_t i = 0; i < sells_count; i++)
	{
		cin >> current_product_id >> sell_time;
		to_sell.push({ current_product_id, sell_time });
	}

	int queries_count, current_query;
	cin >> queries_count;
	vector<pair<int, int>> queries;

	for (size_t i = 0; i < queries_count; i++)
	{
		cin >> current_query;
		queries.push_back({ current_query, i });
	}

	sort(queries.begin(), queries.end());

	int current_query_index = 0;
	int current_best_product_id = -1;
	int current_best_product_sales_count = 0;

	vector<int> results(queries_count);
	unordered_map<int, int> products_sales_count;

	while (to_sell.size() && current_query_index < queries_count)
	{
		if (to_sell.top().time > queries[current_query_index].first) 
		{
			results[queries[current_query_index].second] = current_best_product_id;
			current_query_index++;
			continue;
		}
	
		Sale current = to_sell.top();
		to_sell.pop();

		if (!products_sales_count.count(current.product_id))
			products_sales_count[current.product_id] = 0;

		products_sales_count[current.product_id]++;

		if (products_sales_count[current.product_id] >= current_best_product_sales_count) 
		{
			current_best_product_id = current.product_id;
			current_best_product_sales_count = products_sales_count[current.product_id];
		}
	}

	while (current_query_index < queries_count)
		results[queries[current_query_index++].second] = current_best_product_id;

	for (size_t i = 0; i < queries_count; i++)
		cout << results[i] << '\n';
}