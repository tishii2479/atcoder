#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    using P = pair<string, int>;
    vector<P> t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        t[i] = {s[i], i};

        string trimmed = "";
        bool non = false;
        for (int j = 0; j < t[i].first.length(); j++) {
            if (t[i].first[j] != '0') non = true;
            if (non == false) continue;
            trimmed += t[i].first[j];
        }
        t[i].first = trimmed;
    }

    sort(t.begin(), t.end(), [](P a, P b) {
        if (a.first.length() != b.first.length()) {
            return a.first.length() < b.first.length();
        }
        return a.first < b.first;
    });

    for (int i = 0; i < n; i++) {
        string cur = t[i].first;
        vector<P> v;
        while (i < n and t[i].first == cur) {
            int idx = t[i].second;
            v.push_back({s[idx], idx});
            i++;
        }
        i--;

        sort(v.begin(), v.end(), [](P a, P b) {
            return a.first.length() > b.first.length();
        });

        for (auto p : v) cout << p.first << endl;
    }
}
