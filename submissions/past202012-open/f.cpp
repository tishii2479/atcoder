#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m), c(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--, c[i]--;
    }

    int x = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        int used = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) used |= (1 << i);
        }

        bool ok = true;
        set<int> st;
        for (int i = 0; i < m; i++) {
            int dup = ((used & (1 << a[i])) > 0) + ((used & (1 << b[i])) > 0) + ((used & (1 << c[i])) > 0);
            if (dup == 3) ok = false;
            if (dup == 2) {
                if (!(used & (1 << a[i])))
                    st.insert(a[i]);
                else if (!(used & (1 << b[i])))
                    st.insert(b[i]);
                else if (!(used & (1 << c[i])))
                    st.insert(c[i]);
            }
        }
        if (!ok) continue;
        x = max(x, (int)st.size());
    }
    cout << x << endl;
}
