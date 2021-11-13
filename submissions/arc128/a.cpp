#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    a.push_back(1LL << 60);
    vector<int> res(n);
    bool is_gold = true;
    for (int i = 0; i < n; i++) {
        if (is_gold) {
            if (a[i] > a[i + 1]) {
                is_gold = false;
                res[i] = 1;
            } else {
                res[i] = 0;
            }
        } else {
            if (a[i] < a[i + 1]) {
                res[i] = 1;
                is_gold = true;
            } else {
                res[i] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}
