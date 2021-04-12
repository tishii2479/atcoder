#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
const int inf = 100000000;
vector<vector<int>> S;
vector<vector<int>> counts;
int h, w;
struct Point {
    int x;
    int y;
    Point near(int _x, int _y) {
        Point p;
        p.x = x + _x;
        p.y = y + _y;
        return p;
    }
};
Point newPoint(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
void bfs(Point c) {
    queue<Point> q;
    queue<Point> now;
    q.push(c);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            counts[y][x] = inf;
        }
    }
    counts[c.y][c.x] = 0;
    Point u;
    while (q.empty() == false) {
        while (q.empty() == false) {
            u = q.front();
            q.pop();
            now.push(u);
            if (u.x + 1 < w && S[u.y][u.x + 1] == 0 && counts[u.y][u.x + 1] > counts[u.y][u.x]) {
                counts[u.y][u.x + 1] = counts[u.y][u.x];
                q.push(u.near(1, 0));
                now.push(u.near(1, 0));
            }
            if (u.x - 1 > 0 && S[u.y][u.x - 1] == 0 && counts[u.y][u.x - 1] > counts[u.y][u.x]) {
                counts[u.y][u.x - 1] = counts[u.y][u.x];
                q.push(u.near(-1, 0));
                now.push(u.near(-1, 0));
            }
            if (u.y + 1 < h && S[u.y + 1][u.x] == 0 && counts[u.y + 1][u.x] > counts[u.y][u.x]) {
                counts[u.y + 1][u.x] = counts[u.y][u.x];
                q.push(u.near(0, 1));
                now.push(u.near(0, 1));
            }
            if (u.y - 1 > 0 && S[u.y - 1][u.x] == 0 && counts[u.y - 1][u.x] > counts[u.y][u.x]) {
                counts[u.y - 1][u.x] = counts[u.y][u.x];
                q.push(u.near(0, -1));
                now.push(u.near(0, -1));
            }
        }
        while (now.empty() == false) {
            u = now.front();
            now.pop();
            for (int y = u.y - 2; y <= u.y + 2; y++) {
                for (int x = u.x - 2; x <= u.x + 2; x++) {
                    if (y < 0 || y > h - 1 || x > w - 1 || x < 0)
                        continue;
                    if (S[y][x] == 0 && counts[y][x] > counts[u.y][u.x] + 1) {
                        counts[y][x] = counts[u.y][u.x] + 1;
                        q.push(newPoint(x, y));
                    }
                }
            }
        }
    }
}
int main() {
    cin >> h >> w;
    Point c, d;
    cin >> c.y >> c.x;
    cin >> d.y >> d.x;
    c.x--;
    c.y--;
    d.x--;
    d.y--;
    S = vector<vector<int>>(h, vector<int>(w, 0));
    counts = vector<vector<int>>(h, vector<int>(w, 0));
    char s;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> s;
            if (s == '.') {
                S[y][x] = 0;
            } else {
                S[y][x] = 1;
            }
        }
    }
    bfs(c);
    if (counts[d.y][d.x] == inf) {
        cout << -1 << endl;
    } else {
        cout << counts[d.y][d.x] << endl;
    }
}