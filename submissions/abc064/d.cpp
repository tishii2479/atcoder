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
    string s;
    cin >> n >> s;
    int lcnt = 0;
    int rcnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            lcnt++;
        else {
            rcnt++;
            if (lcnt > 0) {
                rcnt--, lcnt--;
            }
        }
    }
    for (int i = 0; i < rcnt; i++)
        cout << '(';
    cout << s;
    for (int i = 0; i < lcnt; i++)
        cout << ')';
    cout << endl;
}