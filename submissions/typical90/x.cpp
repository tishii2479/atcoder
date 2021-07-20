#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) cnt += abs(a[i] - b[i]);

    if (cnt > k) return false;
    if ((cnt - k) % 2 == 0) return true;
    return false;
}

int main() {
    cout << (solve() ? "Yes" : "No") << endl;
}
