#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int m, k;
    cin >> m >> k;
    int cur = 1 << m;
    // cur = max + 1
    if (k >= cur) {
        cout << -1 << endl;
        return 0;
    }
    if (m == 1) {
        if (k == 0)
            cout << "0 0 1 1" << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < cur; i++)
        if (i != k)
            cout << i << " ";
    cout << k << " ";
    for (int i = cur - 1; i >= 0; i--)
        if (i != k)
            cout << i << " ";
    cout << k << endl;
}