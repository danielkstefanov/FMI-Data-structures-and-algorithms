#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

	void dfs(int current, unordered_set<int>& visited, vector<vector<int>>& graph)
	{
		visited.insert(current);

		for (int neighbour = 0; neighbour < graph.size();neighbour++)
		{
			if (graph[current][neighbour] && !visited.count(neighbour))
				dfs(neighbour, visited, graph);
		}

	}
	int findCircleNum(vector<vector<int>>& isConnected) {
		unordered_set<int> visited;
		int components = 0;
		for (int el = 0; el < isConnected.size();el++)
		{
			if (!visited.count(el))
			{
				dfs(el, visited, isConnected);
				components++;
			}
		}

		return components;
	}
};