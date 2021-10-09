#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    const int n = s.length();
    long long ans = -1;
    for (int bit = 0; bit < (1 << n); bit++) {
        vector<long long> a, b;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i))
                a.push_back(s[i] - '0');
            else
                b.push_back(s[i] - '0');
        }
        sort(a.begin(), a.end(), greater<long long>());
        sort(b.begin(), b.end(), greater<long long>());

        long long val_a = 0, val_b = 0;
        for (int ea : a) {
            val_a = val_a * 10 + ea;
        }
        for (int eb : b) {
            val_b = val_b * 10 + eb;
        }
        ans = max(ans, val_a * val_b);
    }
    cout << ans << endl;
}
