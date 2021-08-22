#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        mp[l].push_back(r);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int cur = 0;
    set<int> done;
    for (auto m : mp) {
        cur = m.first;
        if (done.find(cur) != done.end()) continue;

        for (int e : m.second) pq.push(e);

        while (pq.size()) {
            int e = pq.top();
            pq.pop();
            if (cur > e) return false;
            cur++;

            if (mp[cur].size()) {
                done.insert(cur);
                for (int e : mp[cur]) pq.push(e);
            }
        }
    }

    if (pq.size()) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    vector<string> ans;
    while (t--) ans.push_back(solve() ? "Yes" : "No");
    for (auto s : ans) cout << s << endl;
}
