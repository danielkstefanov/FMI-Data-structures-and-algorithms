#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
	struct Video {
		string name;
		int occurences;

		bool operator<(const Video& other) const {
			if (occurences == other.occurences)
				return name > other.name;

			return occurences > other.occurences;
		}
	};

	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
		vector<vector<int>>& friends, int id,
		int level) {

		unordered_set<int> visited;
		visited.insert(id);

		queue<int> current_level;
		current_level.push(id);

		for (int i = 0; i < level; i++) {
			int current_level_size = current_level.size();

			for (int j = 0; j < current_level_size; j++) {
				int current = current_level.front();
				current_level.pop();

				for (int el : friends[current]) {
					if (!visited.count(el)) {
						current_level.push(el);
						visited.insert(el);
					}
				}
			}
		}

		unordered_map<string, int> video_with_occurences;
		while (!current_level.empty()) {
			int friend_id = current_level.front();
			current_level.pop();
			for (const string& video : watchedVideos[friend_id]) {
				video_with_occurences[video]++;
			}
		}

		priority_queue<Video> videos;

		for (const pair<string, int>& p : video_with_occurences)
			videos.push({ p.first, p.second });

		vector<string> result;

		while (!videos.empty())
		{
			result.push_back(videos.top().name);
			videos.pop();
		}

		return result;
	}
};