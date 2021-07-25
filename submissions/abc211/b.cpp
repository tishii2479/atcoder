#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> st;
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }
    if (st.size() == 4) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
