#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>
#include <unordered_map>

using namespace std;

struct SpeedEdge {
	int from, to, optimal_speed;

	SpeedEdge(int from, int to, int optimal_speed) : from(from), to(to), optimal_speed(optimal_speed) {}
};

class UnionFindWithComponents
{
private:
	vector<size_t> parents;
	vector<size_t> sizes;
	size_t components_count;

	size_t get_parent(size_t vertex)
	{
		if (parents[vertex] == vertex)
			return vertex;

		return parents[vertex] = get_parent(parents[vertex]);
	}
public:

	UnionFindWithComponents(size_t vertices_count) : parents(vertices_count), sizes(vertices_count), components_count(vertices_count)
	{
		for (size_t i = 0; i < vertices_count; i++)
		{
			parents[i] = i;
			sizes[i] = 1;
		}
	}

	size_t get_components_count() const
	{
		return this->components_count;
	}

	bool are_in_one_set(size_t first, size_t second)
	{
		return get_parent(first) == get_parent(second);
	}


	void union_vertices(size_t first, size_t second)
	{
		size_t first_parent = get_parent(first);
		size_t second_parent = get_parent(second);

		if (first_parent == second_parent)
			return;

		if (sizes[first_parent] < sizes[second_parent])
			swap(first_parent, second_parent);

		parents[second_parent] = first_parent;
		sizes[first_parent] += sizes[second_parent];
		components_count--;
	}
};

bool kruskal(int n, vector<SpeedEdge>& edges, int& min, int& max, int skip_count) {
	UnionFindWithComponents uf(n + 1);
	vector<SpeedEdge> mstEdges;

	for (size_t i = skip_count; i < edges.size(); i++) {
		if (uf.are_in_one_set(edges[i].from, edges[i].to))
			continue;

		uf.union_vertices(edges[i].from, edges[i].to);
		mstEdges.push_back(edges[i]);

		if (mstEdges.size() == n - 1)
			break;
	}

	if (mstEdges.size() < n - 1)
		return false;

	min = mstEdges[0].optimal_speed;
	max = mstEdges[mstEdges.size() - 1].optimal_speed;

	return true;
}


int main()
{
	int cities_count, roads_count, from, to, optimal_speed;
	cin >> cities_count >> roads_count;

	vector<SpeedEdge> edges;

	for (size_t i = 0; i < roads_count; i++)
	{
		cin >> from >> to >> optimal_speed;
		edges.push_back({ from, to, optimal_speed });
		edges.push_back({ to, from, optimal_speed });
	}

	sort(edges.begin(), edges.end(), [](const SpeedEdge& a, const SpeedEdge& b) {
		return a.optimal_speed < b.optimal_speed;
		});

	int min = INT_MAX;
	int max = INT_MAX;
	int best_difference = INT_MAX;

	int current_min = edges[0].optimal_speed;
	int current_max = edges[0].optimal_speed;

	int skip_count = 0;

	while (kruskal(cities_count, edges, current_min, current_max, skip_count))
	{
		int current_difference = current_max - current_min;

		if (best_difference > current_difference || (best_difference == current_difference && current_min < min))
		{
			min = current_min;
			max = current_max;
			best_difference = current_difference;
		}

		skip_count++;
	}

	cout << min << ' ' << max;
}