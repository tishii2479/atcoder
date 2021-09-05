#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, q;
    cin >> l >> q;
    set<int> st;
    st.insert(0), st.insert(l);
    for (int i = 0; i < q; i++) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            st.insert(x);
        } else {
            auto it = st.upper_bound(x);
            int r = *it;
            it--;
            int l = *it;
            cout << r - l << endl;
        }
    }
}
