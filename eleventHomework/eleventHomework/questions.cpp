#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class UnionFind {
private:
	std::vector<size_t> parentsContainer;
	std::vector<size_t> sizes;

    size_t get_parent(size_t vertex) {
        if (parentsContainer[vertex] == vertex) {
            return vertex;
        }

        return parentsContainer[vertex] = get_parent(parentsContainer[vertex]);
    }

public:
    UnionFind(size_t vertices) : parentsContainer(vertices), sizes(vertices) {
        for (size_t i = 0; i < vertices; i++) {
            parentsContainer[i] = i;
            sizes[i] = 1;
        }
    }

    bool are_in_one_set(size_t first, size_t second) {
        return get_parent(first) == get_parent(second);
    }

    void union_vertices(size_t first, size_t second) {
        size_t parentOfFirst = get_parent(first);
        size_t parentOfSecond = get_parent(second);

        if (parentOfFirst == parentOfSecond)
            return;

        if (sizes[parentOfFirst] < sizes[parentOfSecond])
            std::swap(parentOfFirst, parentOfSecond);

        parentsContainer[parentOfSecond] = parentOfFirst;
        sizes[parentOfFirst] += sizes[parentOfSecond];
    }
};


void questions() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int cities_count, valid_paths_count, from, to;
	cin >> cities_count >> valid_paths_count;

    UnionFind uf(cities_count+1);

	for (size_t i = 0; i < valid_paths_count; i++)
	{
        cin >> from >> to;
        uf.union_vertices(from, to);
	}

    int queries_count, query_type;
    cin >> queries_count;

    for (size_t i = 0; i < queries_count; i++)
    {
        cin >> query_type >> from >> to;

        if (query_type == 1)
            cout << uf.are_in_one_set(from, to);
        else if (query_type == 2)
            uf.union_vertices(from, to);
    }
}
