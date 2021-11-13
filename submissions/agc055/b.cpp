#include <bits/stdc++.h>
using namespace std;

bool ok(char a, char b, char c) {
    if ((a == 'A' and b == 'B' and c == 'C') or
        (a == 'B' and b == 'C' and c == 'A') or
        (a == 'C' and b == 'A' and c == 'B')) {
        return true;
    }
    return false;
}

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    vector<char> s_v;
    int s_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s_v.size() >= 2 and ok(s_v[s_v.size() - 2], s_v[s_v.size() - 1], s[i])) {
            s_cnt += 3;
            s_v.pop_back();
            s_v.pop_back();
        } else {
            s_v.push_back(s[i]);
        }
    }

    vector<char> t_v;
    int t_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (t_v.size() >= 2 and ok(t_v[t_v.size() - 2], t_v[t_v.size() - 1], t[i])) {
            t_cnt += 3;
            t_v.pop_back();
            t_v.pop_back();
        } else {
            t_v.push_back(t[i]);
        }
    }

    if (s_v == t_v) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
