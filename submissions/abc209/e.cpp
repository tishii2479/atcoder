#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, vector<string>> edges, rev_edges;
    set<string> st;
    map<string, int> dp;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        string head = s[i].substr(0, 3);
        string tail = s[i].substr(s[i].length() - 3, 3);
        edges[head].push_back(tail);
        rev_edges[tail].push_back(head);
        st.insert(head), st.insert(tail);
    }

    queue<string> q;
    for (auto s : st) {
        if (edges[s].size() == 0) {
            q.push(s);
            dp[s] = -1;
        }
    }

    map<string, int> win_cnt;

    while (q.size()) {
        auto v = q.front();
        q.pop();
        for (auto u : rev_edges[v]) {
            if (dp[u] != 0) continue;
            win_cnt[u]++;
            if (dp[v] == -1) {
                dp[u] = 1;
                q.push(u);
            } else if (win_cnt[u] == edges[u].size()) {
                dp[u] = -1;
                q.push(u);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        string tail = s[i].substr(s[i].length() - 3, 3);
        if (dp[tail] == -1)
            cout << "Takahashi" << endl;
        else if (dp[tail] == 1)
            cout << "Aoki" << endl;
        else
            cout << "Draw" << endl;
    }
}
