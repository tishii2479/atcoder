#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007
// #define MOD 998244353
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin >> s;
    vector<int> N;
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        int a = s[i] - '0';
        sum += a;
        N.push_back(a);
    }
    if (sum % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N.size(); i++) {
        if ((sum % 3) == (N[i] % 3) and N.size() > 1) {
            cout << 1 << endl;
            return 0;
        }
    }
    int count = 0;
    for (int i = 0; i < N.size(); i++) {
        if ((sum % 3) == (3 - (N[i] % 3))) {
            count += 1;
        }
    }
    if (count > 1 and N.size() > 2) {
        cout << 2 << endl;
        return 0;
    }
    cout << -1 << endl;
}