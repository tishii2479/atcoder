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
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y < b) {
                if (x < a)
                    cout << "1";
                else
                    cout << "0";
            } else {
                if (x < a)
                    cout << "0";
                else
                    cout << "1";
            }
        }
        cout << endl;
    }
}