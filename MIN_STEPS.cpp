/**
You are in an infinite 2D grid where you can move in any of the 8 directions :
(x,y) to
(x+1, y),
(x - 1, y),
(x, y+1),
(x, y-1),
(x-1, y-1),
(x+1,y+1),
(x-1,y+1),
(x+1,y-1)


You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.
Example :
Input : [(0, 0), (1, 1), (1, 2)]
Output : 2


It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).
This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.

Ans:

All we need to do is find the minimum distance (steps) between two points (x1, y1) and (x2, y2)

Let’s say,
sX = diff (x1, x2) or |x1 - x2|
sY = diff (y1, y2) or |y1 - y2|

If sX < sY
Then sX + (sY - sX)
Else sY + (sX - sY)

**/


#include <iostream>
#include <vector>

using namespace std;

int coverPoints(vector<int> &X, vector<int> &Y) {
    int steps = 0;
    for (int i=0; i<X.size()-1; i++) {
        int sX = X[i] > X[i+1] ? X[i] - X[i+1] : X[i+1] - X[i];
        int sY = Y[i] > Y[i+1] ? Y[i] - Y[i+1] : Y[i+1] - Y[i];
        if (sX < sY) {
            steps += sX + (sY - sX);
        } else {
            steps += sY + (sX - sY);
        }
    }
    return steps;
    return 0;
}

int main() {
    int arrx[] = {0, 0, 1};
    int arry[] = {0, 2, 2};
    vector<int> x(arrx, arrx + sizeof(arrx) / sizeof(arrx[0]));
    vector<int> y(arry, arry + sizeof(arry) / sizeof(arry[0]));
    cout << coverPoints(x, y) << endl;
    return 0;
}