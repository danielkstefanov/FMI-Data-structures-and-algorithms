#include "UnionFind.h"

UnionFind::UnionFind(size_t vertices_count) : parents(vertices_count), sizes(vertices_count)
{
	for (size_t i = 0; i < vertices_count; i++)
	{
		parents[i] = i;
		sizes[i] = 1;
	}
}

bool UnionFind::are_in_one_set(size_t first, size_t second) 
{
	return get_parent(first) == get_parent(second);
}

size_t UnionFind::get_parent(size_t vertex)
{
	if (parents[vertex] == vertex)
		return vertex;

	return parents[vertex] = get_parent(parents[vertex]);
}

void UnionFind::union_vertices(size_t first, size_t second)
{
    size_t first_parent = get_parent(first);
    size_t second_parent = get_parent(second);

    if (first_parent == second_parent)
        return;

    if (sizes[first_parent] < sizes[second_parent])
        swap(first_parent, second_parent);

	parents[second_parent] = first_parent;
    sizes[first_parent] += sizes[second_parent];
}