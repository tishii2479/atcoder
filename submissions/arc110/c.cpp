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
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> sousa;
    int now = 1;
    int l = 0;
    for (int i = 0; i < n; i++) {
        // cout << i << " " << now << endl;
        if (now == p[i]) {
            for (int j = i - 1; j >= l; j--) {
                sousa.push_back(j);
                swap(p[j], p[j + 1]);
            }
            now = i + 1;
            // cout << now << endl;
            l = i;
        }
    }
    if (sousa.size() + 1 != n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i + 1 != p[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << sousa[i] + 1 << endl;
    }
}