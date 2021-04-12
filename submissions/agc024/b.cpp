#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
int main() {
    int n;
    cin >> n;
    vector<pint> a(n);
    for (int i = 0; i < n; i++) {
        int _a;
        cin >> _a;
        a[i] = {_a, i};
    }
    sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++) {
    //  cout << a[i].first << " " << a[i].second << endl;
    // }
    int res = 1;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i].second < a[i + 1].second) {
            cnt++;
            res = max(cnt, res);
        } else {
            cnt = 1;
        }
    }
    reverse(a.begin(), a.end());
    cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i].second > a[i + 1].second) {
            cnt++;
            res = max(cnt, res);
        } else {
            cnt = 1;
        }
    }
    cout << n - res << endl;
}