#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> answer;

    for (int i = 0; i < asteroids.size(); i++) {
        int current = asteroids[i];

        if (current < 0) {

            bool toPush = true;
            while (answer.size() > 0 && answer.top() > 0) {
                if (answer.top() < -current) {
                    answer.pop();
                }
                else if (answer.top() == -current)
                {
                    answer.pop();
                    toPush = false;
                    break;
                }
                else {
                    break;
                }
            }

            if (((answer.size() != 0 && answer.top() < 0) ||
                answer.size() == 0) && toPush) {
                answer.push(current);
            }
        }
        else {
            answer.push(current);
        }
    }

    vector<int> answerVector(answer.size());

    while (answer.size() > 0) {
        answerVector[answer.size() - 1] = answer.top();
        answer.pop();
    }

    return answerVector;
}


int main()
{
    vector<int> v = { -2,1,1,-1 };

    asteroidCollision(v);
}