#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    set<char> st;
    for (char e : s) st.insert(e);
    int cnt = st.size();
    if (cnt == 3) {
        cout << 6 << endl;
    } else if (cnt == 2) {
        cout << 3 << endl;
    } else {
        cout << 1 << endl;
    }
}
