#include <bits/stdc++.h>

#include <string>
using namespace std;
int main() {
    int k;
    string s;
    cin >> k >> s;
    int l = s.size();
    if (k >= l) {
        cout << s << endl;
    } else {
        cout << s.substr(0, k) << "..." << endl;
    }
}