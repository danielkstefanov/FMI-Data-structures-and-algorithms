#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct KruskalEdge {
	int from, to, weight;

	KruskalEdge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
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

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {

	vector<KruskalEdge > edges;

	for (int i = 0; i < g_from.size(); i++)
	{
		edges.push_back({ g_from[i], g_to[i], g_weight[i] });
		edges.push_back({ g_to[i], g_from[i], g_weight[i] });
	}

	std::sort(edges.begin(), edges.end(), [](const KruskalEdge& a, const KruskalEdge& b) {
		return a.weight < b.weight;
		});

	UnionFindWithComponents uf(g_nodes);
	int res = 0;
	for (size_t i = 0; i < edges.size(); i++) {
		if (uf.are_in_one_set(edges[i].from - 1, edges[i].to - 1)) {
			continue;
		}

		uf.union_vertices(edges[i].from - 1, edges[i].to - 1);
		res += edges[i].weight;

		if (uf.get_components_count() == 1) 
			break;
	}

	return res;
}

