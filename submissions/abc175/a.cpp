#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin >> s;
    int cnt = 0;
    int maxv = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'R') {
            cnt += 1;
        } else {
            maxv = max(maxv, cnt);
            cnt = 0;
        }
    }
    maxv = max(maxv, cnt);
    cout << maxv << endl;
}