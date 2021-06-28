#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int median = a[n / 2];

    double ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (double)median / 2 + a[i] - min(a[i], median);
    }
    ans /= n;

    printf("%.10lf\n", ans);
}
