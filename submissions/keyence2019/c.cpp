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
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int cnt = 0;
    ll need = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < b[i])
            need += b[i] - a[i], cnt++;
    if (need == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> able;
    for (int i = 0; i < n; i++)
        if (a[i] - b[i] > 0)
            able.push_back(a[i] - b[i]);
    sort(able.begin(), able.end(), greater<ll>());
    for (int i = 0; i < able.size(); i++) {
        need -= able[i];
        if (need <= 0) {
            cout << cnt + i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}