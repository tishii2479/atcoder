#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<long long> p(n), t(n);
    for (int i = 0; i < n; i++) cin >> p[i] >> t[i];

    vector<long long> need, non;
    for (int i = 0; i < n; i++) {
        if (t[i] == 1)
            need.push_back(p[i]);
        else
            non.push_back(p[i]);
    }

    sort(need.begin(), need.end());
    sort(non.begin(), non.end());

    vector<long long> need_sum(need.size() + 1, 0), non_sum(non.size() + 1, 0);
    for (int i = 0; i < need.size(); i++) need_sum[i + 1] += need_sum[i] + need[i];
    for (int i = 0; i < non.size(); i++) non_sum[i + 1] += non_sum[i] + non[i];

    long long ans = 1LL << 60;
    for (int i = 0; i < need_sum.size(); i++) {
        // i := need number
        long long cost = (i + k - 1) / k * q;
        if (m - i < 0) continue;
        if (m - i >= non_sum.size()) continue;
        cost += need_sum[i] + non_sum[m - i];
        ans = min(cost, ans);
    }
    cout << ans << endl;
}
