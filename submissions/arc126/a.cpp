#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll solve() {
    ll n1, n3, n2;
    cin >> n1 >> n3 >> n2;
    n3 /= 2;
    ll ans = 0;

    ll n23 = min(n2, n3);
    n2 -= n23, n3 -= n23;
    ans += n23;

    if (n2 > 0) {
        ll n12 = min(n2 / 2, n1);
        ans += n12;
        n1 -= n12, n2 -= n12 * 2;
        if (n2 % 2 == 1) {
            n1 += 2;
        }
    } else if (n3 > 0) {
        ll n13 = min(n1 / 2, n3);
        ans += n13;
        n1 -= n13 * 2, n3 -= n13;
    }
    ans += n1 / 5;

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
