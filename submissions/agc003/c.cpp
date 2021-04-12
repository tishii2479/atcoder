#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<pint> ai(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ai[i] = {a, i};
    }
    sort(ai.begin(), ai.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ai[i].second % 2 != i % 2)
            ans++;
    }
    cout << ans / 2 << endl;
}