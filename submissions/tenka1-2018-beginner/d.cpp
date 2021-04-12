#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int table[1100][1100];
int main() {
    ll n;
    cin >> n;
    bool flag = false;
    ll t;
    for (ll i = 0; i * i < 210000; i++) {
        if (i * (i + 1) / 2 == n) {
            t = i + 1;
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << t << endl;
    ll cnt = 1;
    for (ll i = 0; i < 1100; i++) {
        for (ll j = 0; j < i + 1; j++) {
            table[i][j] = cnt;
            cnt++;
        }
    }
    for (ll i = 0; i < t - 1; i++) {
        cout << t - 1 << " ";
        for (ll j = 0; j < i; j++) {
            cout << table[i][j] << " ";
        }
        for (ll j = 0; j < t - i - 1; j++) {
            cout << table[j + i][i] << " ";
        }
        cout << endl;
    }
    cout << t - 1 << " ";
    for (ll i = 0; i < t - 1; i++) {
        cout << table[i][i] << " ";
    }
    cout << endl;
}