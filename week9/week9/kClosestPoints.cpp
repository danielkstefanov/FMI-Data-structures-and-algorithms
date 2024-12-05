#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct Point {
        int x;
        int y;

        Point(int _x, int _y) {
            this->x = _x;
            this->y = _y;
        }
    };

    struct PointMinComparator {
        bool operator()(const Point& p1, const Point& p2) {

            double p1Distance = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
            double p2Distance = sqrt(pow(p2.x, 2) + pow(p2.y, 2));
            return p1Distance > p2Distance;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        priority_queue<Point, vector<Point>, PointMinComparator> pq;

        for (vector<int> currentPointCoordinates : points) {
            Point currentPoint(currentPointCoordinates[0],
                currentPointCoordinates[1]);
            pq.push(currentPoint);
        }

        while (k > 0 && pq.size()) {
            Point p = pq.top();
            pq.pop();
            result.push_back({ p.x, p.y });
            k--;
        }

        return result;
    }
};