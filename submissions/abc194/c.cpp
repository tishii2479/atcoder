#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * a[i] * (n - 1);
    }
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        ans += (sum - a[i]) * a[i] * -1;
    }
    cout << ans << endl;
}