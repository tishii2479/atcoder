#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll t, n;
    cin >> t >> n;
    ll mul = n / t;
    ll cur = 100 * mul;
    ll remain = n - mul * t;
    // cout << mul << " " << cur << " " << remain << endl;

    set<ll> st;
    for (int i = 0; i < 300; i++) {
        st.insert((100 + t) * (cur + i) / 100);
        // cout << (100 + t) * (cur + i) / 100 << endl;
    }

    ll now = (100 + t) * mul - 1;
    while (remain > 0) {
        now++;
        // cout << now << " " << remain << endl;
        if (st.find(now) == st.end()) remain--;
    }

    cout << now << endl;
}
