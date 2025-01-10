#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

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

void snow_road_cleaning_hours()
{
    int  intersections_count, roads_count, from, to;
    cin >> intersections_count >> roads_count;

    if (intersections_count == 1)
    {
        cout << 0;
        return;
    }

    UnionFindWithComponents uf(intersections_count);

    int min_hours = -1;

    for (size_t i = 1; i <= roads_count; i++)
    {
        cin >> from >> to;

        uf.union_vertices(from - 1, to - 1);

        if (uf.get_components_count() == 1)
        {
            min_hours = i;
            break;
        }
    }

    cout << min_hours;
}