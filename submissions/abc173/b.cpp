#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1ll << 60;
const int inf = 1 << 29;
int main() {
    int n;
    cin >> n;
    string key[4] = {"AC", "WA", "TLE", "RE"};
    vector<int> counts = vector<int>(4, 0);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < 4; j++) {
            if (s == key[j])
                counts[j]++;
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << key[i] << " x " << counts[i] << endl;
    }
}