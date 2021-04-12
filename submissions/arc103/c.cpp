#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[n - 1] == '1' or s[0] == '0') {
        cout << -1 << endl;
        return 0;
    }
    vector<pint> edges;
    edges.push_back({0, 1});
    int parent = 1;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] != s[n - i - 2]) {
            cout << -1 << endl;
            return 0;
        }
        if (s[i] == '1') {
            edges.push_back({parent, i + 1});
            parent = i + 1;
        } else {
            edges.push_back({parent, i + 1});
        }
    }
    for (pint p : edges) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}