#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1ll << 60;
const int inf = 1 << 29;
int main() {
    string s, t;
    cin >> s >> t;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i])
            count++;
    }
    cout << count << endl;
}