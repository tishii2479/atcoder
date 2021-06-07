#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    n *= 2;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<int> color(n);

    for (int i = 0; i < n; i++) {
        color[a[i].second] = i < n / 2;
    }

    vector<char> s(n);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        if (st.size() == 0) {
            st.push({i, color[i]});
        } else {
            auto p = st.top();
            if (p.second != color[i]) {
                st.pop();
                s[p.first] = '(';
                s[i] = ')';
            } else {
                st.push({i, color[i]});
            }
        }
    }

    for (int i = 0; i < n; i++) cout << s[i];
    cout << endl;
}
