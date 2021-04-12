#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (Int i = 0; i < n; i++)
#define repd(i, n) for (Int i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> paths(n);
    int a, b;
    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    vector<bool> found(n, false);
    found[0] = true;
    queue<int> queue;
    queue.push(0);
    vector<int> dist(n, inf);
    dist[0] = 0;
    vector<int> prev(n);
    while (queue.empty() == false) {
        int p = queue.front();
        queue.pop();
        for (int i = 0; i < paths[p].size(); i++) {
            int next = paths[p][i];
            found[next] = true;
            if (dist[p] + 1 < dist[next]) {
                prev[next] = p;
                dist[next] = dist[p] + 1;
                queue.push(next);
            }
        }
    }
    bool flag = true;
    rep(i, n) {
        if (found[i] == false) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
        for (int i = 1; i < n; i++) {
            cout << prev[i] + 1 << endl;
        }
    } else {
        cout << "No" << endl;
    }
}