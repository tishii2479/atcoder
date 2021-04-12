#include <bits/stdc++.h>
using namespace std;
int main() {
    const int N = 110000;
    int n;
    cin >> n;
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        if (i > 0)
            sum += cnt[i - 1];
        sum += cnt[i];
        if (i < N - 1)
            sum += cnt[i + 1];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}