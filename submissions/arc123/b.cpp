#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    int cnt = 0;

    priority_queue<int> pq;

    int cur = 0;
    priority_queue<int> ok;

    for (int i = 0; i < n; i++) {
        while (cur < n and c[cur] > b[i]) {
            pq.push(c[cur]);
            cur++;
        }

        if (pq.size()) {
            pq.pop();
            ok.push(b[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (ok.size() == 0) break;

        if (a[i] < ok.top()) {
            ok.pop();
            cnt++;
        }
    }

    cout << cnt << endl;
}
