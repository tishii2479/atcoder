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
    vector<pll> task;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        task.push_back({b, a});
    }
    sort(task.begin(), task.end());
    bool ok = true;
    ll now = 0;
    for (int i = 0; i < n; i++) {
        now += task[i].second;
        if (now > task[i].first) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}