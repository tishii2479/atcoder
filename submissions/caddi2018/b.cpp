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
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a % 2 == 1) {
            cout << "first" << endl;
            return 0;
        }
    }
    cout << "second" << endl;
}