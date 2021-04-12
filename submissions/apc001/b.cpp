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
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ll need = 0;
    ll afford = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i])
            need += a[i] - b[i];
        else if (a[i] < b[i])
            afford += (b[i] - a[i]) / 2;
    }
    if (need <= afford)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}