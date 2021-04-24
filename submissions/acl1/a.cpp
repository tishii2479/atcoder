#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> xyi(n);
    for (int i = 0; i < n; i++) {
        cin >> xyi[i].first.first >> xyi[i].first.second;
        xyi[i].second = i;
    }

    sort(xyi.begin(), xyi.end());

    dsu uf(n);
    set<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        int y = xyi[i].first.second, idx = xyi[i].second;

        if (st.empty() or st.begin()->first > y) {
            st.insert({y, idx});
            continue;
        }

        for (auto it = st.begin(); it != st.end();) {
            if (it->first < y) {
                uf.merge(idx, it->second);
                if (it != st.begin()) {
                    it = st.erase(it);
                } else {
                    it++;
                }
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << uf.size(i) << endl;
}
