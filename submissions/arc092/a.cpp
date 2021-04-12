#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<pint> red(n);
    vector<pint> blue(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        red[i] = {x, y};
    }
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        blue[i] = {y, x};
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < blue.size(); j++) {
            if (red[i].first < blue[j].second and red[i].second < blue[j].first) {
                red.erase(red.begin() + i);
                blue.erase(blue.begin() + j);
                j--;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}