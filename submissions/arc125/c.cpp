#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    vector<int> p;
    set<int> st;
    for (int i = 0; i < k; i++) st.insert(a[i]);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
        if (st.find(i) == st.end()) pq.push(i);

    for (int i = 0; i < k - 1; i++) {
        p.push_back(a[i]);

        if (pq.size()) {
            if (pq.top() < a[i]) {
                p.push_back(pq.top());
                pq.pop();
            }
        }
    }

    pq.push(a[k - 1]);

    vector<int> v;
    while (pq.size()) {
        v.push_back(pq.top());
        pq.pop();
    }

    reverse(v.begin(), v.end());
    for (int e : v) p.push_back(e);

    for (int e : p) cout << e << " ";
    cout << endl;
}
