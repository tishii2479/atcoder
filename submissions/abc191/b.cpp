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
    int n, x;
    cin >> n >> x;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (b != x)
            a.push_back(b);
    }
    for (int s : a) {
        cout << s << " ";
    }
    cout << endl;
}