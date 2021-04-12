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
    int n;
    cin >> n;
    int now = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        now = max(now, a);
        if (a < now) {
            ans += now - a;
        }
    }
    cout << ans << endl;
}