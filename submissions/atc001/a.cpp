#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1ll << 60;
const int inf = 1 << 29;
struct Point {
    int x;
    int y;
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};
Point unit[4] = {
    Point(1, 0),
    Point(-1, 0),
    Point(0, 1),
    Point(0, -1),
};
Point addPoint(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}
bool isInField(Point p, Point u, int h, int w) {
    if (0 <= p.x + u.x and p.x + u.x < w and 0 <= p.y + u.y and p.y + u.y < h)
        return true;
    return false;
}
char C[510][510];
bool found[510][510];
Point s = Point(0, 0);
Point g = Point(0, 0);
int H, W;
bool dfs(Point s) {
    stack<Point> S;
    S.push(s);
    while (S.empty() == false) {
        Point u = S.top();
        S.pop();
        for (int i = 0; i < 4; i++) {
            Point n = addPoint(u, unit[i]);
            if (isInField(u, unit[i], H, W) and C[n.y][n.x] != '#' and found[n.y][n.x] == false) {
                S.push(n);
                found[n.y][n.x] = true;
                if (C[n.y][n.x] == 'g')
                    return true;
            }
        }
    }
    return false;
}
int main() {
    cin >> H >> W;
    char c;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c;
            C[i][j] = c;
            if (c == 's')
                s = Point(j, i);
            else if (c == 'g')
                g = Point(j, i);
            found[i][j] = false;
        }
    }
    found[s.y][s.x] = true;
    if (dfs(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}