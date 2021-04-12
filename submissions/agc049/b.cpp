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
    string s, t;
    cin >> n;
    cin >> s >> t;
    int scnt = 0;
    int tcnt = 0;
    vector<ll> sindex;
    vector<ll> tindex;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            scnt++;
            sindex.push_back(i);
        }
        if (t[i] == '1') {
            tcnt++;
            tindex.push_back(i);
        }
        // if (scnt > tcnt)
        // {
        //     cout << -1 << endl;
        //     return 0;
        // }
    }
    if (scnt < tcnt) {
        cout << -1 << endl;
        return 0;
    }
    if ((scnt - tcnt) % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    ll cnt = 0;
    int j = 0;
    for (int i = 0; i < tcnt; i++) {
        vector<ll> now;
        if (j >= scnt) {
            cout << -1 << endl;
            return 0;
        }
        while (sindex[j] < tindex[i]) {
            now.push_back(sindex[j]);
            j++;
            if (j >= scnt) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (now.size() % 2 == 1) {
            now.push_back(sindex[j]);
            j++;
            if (j >= scnt) {
                cout << -1 << endl;
                return 0;
            }
        }
        for (int k = 0; k < now.size(); k += 2) {
            cnt += now[k + 1] - now[k];
        }
        cnt += sindex[j] - tindex[i];
        j++;
        // cout << j << " " << cnt << endl;
    }
    for (int i = j; i < scnt; i += 2) {
        cnt += sindex[i + 1] - sindex[i];
    }
    cout << cnt << endl;
}