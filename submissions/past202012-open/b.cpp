#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string t = "";
    for (int i = 0; i < n; i++) {
        string new_t = "";
        for (int j = 0; j < t.length(); j++) {
            if (s[i] != t[j]) new_t += t[j];
        }
        t = new_t;
        t += s[i];
    }
    cout << t << endl;
}
