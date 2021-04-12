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
    int a, b;
    cin >> a >> b;
    if (a + b >= 15 and b >= 8) {
        cout << 1 << endl;
    } else if (a + b >= 10 and b >= 3) {
        cout << 2 << endl;
    } else if (a + b >= 3) {
        cout << 3 << endl;
    } else {
        cout << 4 << endl;
    }
}