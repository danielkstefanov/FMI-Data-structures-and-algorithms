#pragma once
#include <vector>

using namespace std;

class UnionFind 
{
private:
	vector<size_t> parents;
	vector<size_t> sizes;

	size_t get_parent(size_t vertex);
public:
	UnionFind(size_t vertices_count);

	bool are_in_one_set(size_t first, size_t second);
	void union_vertices(size_t first, size_t second);
};