#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {

	vector<int> result(n - 1, -1);
	unordered_map<int, unordered_set<int>> graph;
	for (int i = 0; i < edges.size();i++)
	{
		graph[edges[i][0]].insert(edges[i][1]);
		graph[edges[i][1]].insert(edges[i][0]);
	}

	queue<int> currentLevel;
	unordered_set<int> visited;
	visited.insert(s);
	currentLevel.push(s);

	int distance = 1;

	while (currentLevel.size())
	{
		int levelSize = currentLevel.size();

		for (int i = 0; i < levelSize;i++)
		{
			int currentNode = currentLevel.front();
			currentLevel.pop();

			for (int neighbour : graph[currentNode])
			{
				if (!visited.count(neighbour)) {
					visited.insert(neighbour);
					currentLevel.push(neighbour);

					int offset = neighbour > s ? 2 : 1;
					result[neighbour - offset] = distance * 6;
				}
			}

		}

		distance++;
	}


	return result;
}