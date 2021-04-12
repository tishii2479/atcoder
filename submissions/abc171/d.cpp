#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1ll << 60;
const int inf = 1 << 29;
int main() {
    int n, q, b, c;
    cin >> n;
    map<int, int> mp;
    ll sum = 0;
    int x;
    rep(i, n) {
        cin >> x;
        sum += x;
        mp[x]++;
    }
    cin >> q;
    rep(i, q) {
        cin >> b >> c;
        if (mp[b] > 0) {
            sum += (c - b) * mp[b];
            mp[c] += mp[b];
            mp[b] = 0;
        }
        cout << sum << endl;
    }
}