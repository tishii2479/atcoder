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
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    string a, b;
    cin >> a >> b;
    if (a == "H" and b == "H" or a == "D" and b == "D") {
        cout << "H" << endl;
    } else {
        cout << "D" << endl;
    }
}