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
    int d = b - a;
    int cur = 0;
    for (int i = 0; i < d; i++)
        cur += i;
    cout << cur - a << endl;
}