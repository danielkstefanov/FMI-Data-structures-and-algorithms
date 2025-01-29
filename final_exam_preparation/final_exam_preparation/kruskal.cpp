#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Time complexity O(ElogV)


struct UnionFind
{
private:
	vector<int> parents;
	vector<int> sizes;

	int get_parent(int index) 
	{
		if (parents[index] == index)
			return index;

		return parents[index] = get_parent(parents[index]);
	}

public:
	UnionFind(int n) : parents(n), sizes(n) {
		for (size_t i = 0; i < n; i++) {
			parents[i] = i;
			sizes[i] = 1;
		}
	}

	bool areInOneSet(size_t first, size_t second) 
	{
		return get_parent(first) == get_parent(second);
	}

	void unionVertices(size_t first, size_t second) 
	{
		int first_parent = get_parent(first);
		int second_parent = get_parent(second);
	
		if (first_parent == second_parent)
			return;

		if (sizes[first] < sizes[second])
			swap(first, second);

		parents[second_parent] = first_parent;
		sizes[first_parent] += sizes[second_parent];
	}
};

struct Edge
{
	int from, to, weight;
};


vector<Edge> kruskal(int nodes_count, vector<Edge>& edges)
{
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
		return a.weight < b.weight;
		});

	UnionFind uf(nodes_count);

    vector<Edge> mstEdges;
    for (size_t i = 0; i < edges.size(); i++) {
        if (uf.areInOneSet(edges[i].from, edges[i].to))
            continue;

        uf.unionVertices(edges[i].from, edges[i].to);
        mstEdges.push_back(edges[i]);
    }

    return mstEdges;
}