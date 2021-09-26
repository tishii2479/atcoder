#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll pow10(int x) {
    ll res = 1;
    for (int i = 0; i < x; i++) res *= 10;
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll cur = 2;
    ll plus = 0;
    ll ans = 0;
    while (cur <= n) {
        cur *= 10;
        plus = plus * 10 + 1;
        ans += plus;
    }

    string s = to_string(n);
    if (s[0] != '1') {
        cout << ans << endl;
        return 0;
    }
    bool is_bigger = false;
    const int N = s.length();
    for (int i = 0; i < N; i++) {
        if (!is_bigger and s[i] == '0') break;
        if (s[i] - '0' > 1) {
            is_bigger = true;
        }
        if (is_bigger) {
            ans += pow10(N - i - 1);
        } else {
            // simo N - i - 1 桁
            string t = "";
            for (int j = i + 1; j < N; j++) t += s[j];
            if (t == "") t = "0";
            ans += stoll(t) + 1;
        }
    }

    cout << ans << endl;
}
