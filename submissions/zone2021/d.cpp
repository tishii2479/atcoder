#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t = "";
    cin >> s;
    int n = s.length();
    bool flip = true;
    deque<char> deq;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            flip = !flip;
        } else {
            if (flip) {
                deq.emplace_front(s[i]);
            } else {
                deq.emplace_back(s[i]);
            }
        }
    }

    if (flip) reverse(deq.begin(), deq.end());

    stack<char> st;
    for (auto c : deq) {
        if (st.size() and st.top() == c) {
            st.pop();
            continue;
        }
        st.push(c);
    }

    stack<char> tmp;

    while (st.size()) {
        char c = st.top();
        st.pop();
        tmp.push(c);
    }

    while (tmp.size()) {
        char c = tmp.top();
        tmp.pop();
        cout << c;
    }
    cout << endl;
}
