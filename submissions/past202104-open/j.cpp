#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    long long sum_x = 0;
    long long sum = 0;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        sum_x += x[i];
        sum += x[i] * x[i];
        sum += (c - y[i]) * (c - y[i]);
    }

    long double ans = sum - (long double)sum_x / n * sum_x;

    printf("%.15Lf\n", ans);
}
