#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    deque<int> deq;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        int val = i + 1;
        if (c == 'L') {
            deq.push_front(val);
        } else if (c == 'R') {
            deq.push_back(val);
        } else if ('A' <= c and c <= 'C') {
            int v = c - 'A' + 1;
            if (deq.size() < v) {
                cout << "ERROR" << endl;
            } else {
                vector<int> vec;
                for (int i = 0; i < v; i++) {
                    vec.push_back(deq.front());
                    deq.pop_front();
                }
                cout << vec[v - 1] << endl;
                for (int i = v - 2; i >= 0; i--) {
                    deq.push_front(vec[i]);
                }
            }
        } else if ('D' <= c and c <= 'F') {
            int v = c - 'D' + 1;
            if (deq.size() < v) {
                cout << "ERROR" << endl;
            } else {
                vector<int> vec;
                for (int i = 0; i < v; i++) {
                    vec.push_back(deq.back());
                    deq.pop_back();
                }
                cout << vec[v - 1] << endl;
                for (int i = v - 2; i >= 0; i--) {
                    deq.push_back(vec[i]);
                }
            }
        } else {
            assert(false);
        }
    }
}
