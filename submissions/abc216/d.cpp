#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> st;
    vector<vector<int>> v(n + 1);
    vector<stack<int>> a(m);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> t(k);
        for (int j = 0; j < k; j++) cin >> t[j];

        reverse(t.begin(), t.end());

        for (int j = 0; j < k; j++) {
            a[i].push(t[j]);
            v[t[j]].push_back(i);

            if (j == k - 1) {
                st.insert(t[j]);
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (st.count(i) == 2) q.push(i);
    }

    int cnt = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        cnt++;

        for (int e : v[x]) {
            a[e].pop();

            if (a[e].size() > 0) {
                st.insert(a[e].top());
                if (st.count(a[e].top()) == 2) {
                    q.push(a[e].top());
                }
            }
        }
    }

    if (cnt == n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
