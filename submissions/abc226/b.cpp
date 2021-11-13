#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> v;
        for (int j = 0; j < l; j++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        st.insert(v);
    }

    cout << st.size() << endl;
}
