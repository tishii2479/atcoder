#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, k;
    cin >> n >> k;
    if (k > (n - 1) * (n - 2) / 2) {
        cout << -1 << endl;
        return 0;
    }
    int m = (n - 1) + (n - 1) * (n - 2) / 2 - k;
    cout << m << endl;
    for (int i = 1; i < n; i++) {
        cout << 1 << " " << i + 1 << endl;
    }
    int t = (n - 1) * (n - 2) / 2 - k;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            t--;
            if (t < 0)
                return 0;
            cout << i + 1 << " " << j + 1 << endl;
        }
    }
}