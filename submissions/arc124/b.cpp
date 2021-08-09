#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    set<int> st;

    for (int j = 0; j < n; j++) {
        multiset<int> test;
        for (int i = 0; i < n; i++) test.insert(b[i]);

        int val = a[0] ^ b[j];

        bool ok = true;
        for (int i = 0; i < n and ok; i++) {
            int need = val ^ a[i];
            auto it = test.find(need);
            if (it == test.end()) {
                ok = false;
            } else {
                test.erase(it);
            }
        }

        if (ok) {
            st.insert(val);
        }
    }

    cout << st.size() << endl;
    for (auto s : st) cout << s << endl;
}
