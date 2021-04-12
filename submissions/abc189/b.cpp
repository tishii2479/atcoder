#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    int x;
    cin >> n >> x;
    x *= 100;
    for (int i = 0; i < n; i++) {
        int v, p;
        cin >> v >> p;
        x -= v * p;
        if (x < 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}