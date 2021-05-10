#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v = {6, 10, 15, 12, 18, 20, 24, 30};
    int cur = 0;
    int plus = 0;
    while (n--) {
        cout << v[cur] + plus << " ";
        cur++;
        if (cur == 8) {
            cur = 0;
            plus += 30;
        }
    }
    cout << endl;
}
