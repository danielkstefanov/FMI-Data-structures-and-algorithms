#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

struct Node
{
	int x, y, dist;

	bool operator < (const Node& other)const
	{
		return dist > other.dist;
	}
};

vector<pair<int, int>> combinations = { {0,1}, {1,0}, {-1,0}, {0,-1} };

pair<int, int> generate_next_position(int x, int y, int i)
{
	return { x + combinations[i].first,y + combinations[i].second };
}

int dijkstra_leaf(int x, int y, int rows, int cols, vector<vector<char>>& matrix)
{
	vector<vector<int>> shortest_paths(rows, vector<int>(cols, INT_MAX));
	shortest_paths[x][y] = 0;

	priority_queue<Node> pq;
	pq.push({ x,y,0 });

	while (!pq.empty())
	{
		Node current_node = pq.top();
		pq.pop();

		if (current_node.dist > shortest_paths[current_node.x][current_node.y])
			continue;

		// Is on the edge of the matrix (a.k.a end)
		if (current_node.x == 0 || current_node.y == 0 || current_node.x == rows-1 || current_node.y == cols-1)
			return current_node.dist;

		for (size_t i = 0; i < 4; i++)
		{
			pair<int, int> next_position = generate_next_position(current_node.x, current_node.y, i);
			int new_weight = current_node.dist + (matrix[next_position.first][next_position.second] == '#' ? 1 : 0);
			if (new_weight < shortest_paths[next_position.first][next_position.second]) {
				shortest_paths[next_position.first][next_position.second] = new_weight;
				pq.push({ next_position.first,next_position.second, new_weight });
			}
		}
	}

	return -1;
}


int main()
{
	int rows, cols;
	cin >> rows >> cols;

	vector<vector<char>> matrix(rows, vector<char>(cols, '.'));

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			cin >> matrix[i][j];
	}

	int max_shortest_path_len = -1;
	int worst_positions_count = 0;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] == '.')
			{
				int shortest_path_to_leaf = dijkstra_leaf(i, j, rows, cols, matrix);

				if (shortest_path_to_leaf == max_shortest_path_len)
					worst_positions_count++;

				if (shortest_path_to_leaf > max_shortest_path_len)
				{
					max_shortest_path_len = shortest_path_to_leaf;
					worst_positions_count = 1;
				}
			}

		}
	}

	cout << worst_positions_count;
}