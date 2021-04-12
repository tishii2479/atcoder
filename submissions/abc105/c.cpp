#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n;
    cin >> n;
    string str = "";
    while (n != 0) {
        int r = n % 2;
        if (r < 0)
            r += 2;
        n = (n - r) / (-2);
        str += (char)('0' + r);
    }
    reverse(str.begin(), str.end());
    if (str == "")
        str = "0";
    cout << str << endl;
}