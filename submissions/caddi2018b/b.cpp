#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
const ll INF = 1LL << 60;
// #define MOD 998244353
int main() {
    int n, h, w;
    cin >> n >> h >> w;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a >= h and b >= w) {
            cnt++;
        }
    }
    cout << cnt << endl;
}