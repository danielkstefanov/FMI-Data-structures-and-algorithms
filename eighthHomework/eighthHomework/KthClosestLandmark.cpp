#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Landmark
{
    int x;
    int y;
    double distance;

    Landmark(int x, int y, double distance)
    {
        this->x = x;
        this->y = y;
        this->distance = distance;
    }

    bool operator<(const Landmark& rhs) const
    {
        if (distance == rhs.distance)
        {
            if (x == rhs.x)
                return y < rhs.y;
            return x < rhs.x;
        }
        return distance < rhs.distance;
    }
};

double getDistance(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void closestLandmarks()
{
    int X, Y, N, K;
    cin >> X >> Y >> N >> K;

    priority_queue<Landmark> pq;

    for (int i = 0; i < N; i++)
    {
        int currentX, currentY;
        cin >> currentX >> currentY;

        double distance = getDistance(X, Y, currentX, currentY);

        Landmark toPush(currentX, currentY, distance);

        if (pq.size() < K)
        {
            pq.push(toPush);
        }
        else if (!(pq.top() < toPush))
        {
            pq.pop();
            pq.push(toPush);
        }
    }

    vector<Landmark> result;
    while (!pq.empty())
    {
        result.push_back(pq.top());
        pq.pop();
    }

    for (int i = result.size()-1; i >= 0 ; i--)
        cout << result[i].x << " " << result[i].y << '\n';
}
