#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int m = 0; m < 10; m++) {
                    set<int> st;
                    st.insert(i);
                    st.insert(j);
                    st.insert(k);
                    st.insert(m);

                    bool ok = true;
                    for (int t = 0; t < 10; t++) {
                        if (s[t] == 'o') {
                            if (st.find(t) == st.end()) {
                                ok = false;
                            }
                        } else if (s[t] == 'x') {
                            if (st.find(t) != st.end()) {
                                ok = false;
                            }
                        }
                    }
                    if (ok) ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
