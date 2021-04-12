#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
double p[101][101][101];
struct S {
    int a;
    int b;
    int c;
    S(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }
};
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    double sum = 0;
    int n = 101;
    queue<S> queue;
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                p[i][j][k] = -1;
            }
        }
    }
    p[A][B][C] = 1;
    queue.push(S(A + 1, B, C));
    queue.push(S(A, B + 1, C));
    queue.push(S(A, B, C + 1));
    while (queue.empty() == false) {
        S s = queue.front();
        queue.pop();
        int a = s.a;
        int b = s.b;
        int c = s.c;
        double pp = 0;
        if (p[a][b][c] != -1) {
            continue;
        }
        if (p[a][b][c] == -1) {
            if (b != 100 and c != 100 and a > 0 and p[a - 1][b][c] != -1)
                pp += p[a - 1][b][c] * (double(a - 1) / (a - 1 + b + c));
            if (a != 100 and c != 100 and b > 0 and p[a][b - 1][c] != -1)
                pp += p[a][b - 1][c] * (double(b - 1) / (a + b - 1 + c));
            if (a != 100 and b != 100 and c > 0 and p[a][b][c - 1] != -1)
                pp += p[a][b][c - 1] * (double(c - 1) / (a + b + c - 1));
            if (pp == 0) {
                continue;
            }
            p[a][b][c] = pp;
        }
        if (a == 100 or b == 100 or c == 100) {
            sum += (double)(a + b + c - A - B - C) * p[a][b][c];
            continue;
        }
        if (a < 100)
            queue.push(S(a + 1, b, c));
        if (b < 100)
            queue.push(S(a, b + 1, c));
        if (c < 100)
            queue.push(S(a, b, c + 1));
    }
    printf("%.14lf\n", sum);
}