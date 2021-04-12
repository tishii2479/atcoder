#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string a, b;
    cin >> a >> b;
    int c = 0;
    int d = 0;
    for (int i = 0; i < a.length(); i++) {
        c += a[i] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        d += b[i] - '0';
    }
    cout << max(c, d) << endl;
}