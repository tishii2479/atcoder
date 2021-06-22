#include <bits/stdc++.h>
using namespace std;

string solve(int val) {
    if (val < 206) {
        return "Yay!";
    } else if (val == 206) {
        return "so-so";
    } else {
        return ":(";
    }
}

int main() {
    int n;
    cin >> n;
    int val = n * 108 / 100;
    cout << solve(val) << endl;
}
