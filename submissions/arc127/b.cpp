#include <bits/stdc++.h>
using namespace std;

vector<string> s;
string largest = "";
int n, l;
void dfs(string cur) {
    if (cur.length() == l) {
        if (cur < largest) s.push_back(cur);
        return;
    }
    for (int i = 0; i < 3; i++) {
        dfs(cur + (char)(i + '0'));
    }
}

int main() {
    cin >> n >> l;

    int t = n - 1;
    while (t > 0) {
        largest += (t % 3) + '0';
        t /= 3;
    }
    while (largest.size() < l) largest += "0";
    largest[l - 1] = '2';
    reverse(largest.begin(), largest.end());

    s.push_back(largest);
    dfs("2");

    for (string e : s) {
        cout << e << endl;
    }

    for (string e : s) {
        for (int i = 0; i < e.length(); i++) {
            cout << (char)(((e[i] - '0' + 1) % 3) + '0');
        }
        cout << endl;
    }
    for (string e : s) {
        for (int i = 0; i < e.length(); i++) {
            cout << (char)(((e[i] - '0' + 2) % 3) + '0');
        }
        cout << endl;
    }
}
