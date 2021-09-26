#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) sum += a[i];

    printf("%lld\n", sum);

    for (int i = k; i < n; i++) {
        sum += a[i];
        sum -= a[i - k];
        printf("%lld\n", sum);
    }
}
