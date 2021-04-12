#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    int bingo[3][3];
    rep(i, 3) {
        rep(j, 3) {
            cin >> bingo[i][j];
        }
    }
    int n;
    cin >> n;
    rep(i, n) {
        int b;
        cin >> b;
        rep(j, 3) {
            rep(k, 3) {
                if (b == bingo[j][k])
                    bingo[j][k] = 0;
            }
        }
    }
    rep(i, 3) {
        int sum = 0;
        rep(j, 3) {
            sum += bingo[i][j];
        }
        if (sum == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    rep(i, 3) {
        int sum = 0;
        rep(j, 3) {
            sum += bingo[j][i];
        }
        if (sum == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    int sum = 0;
    rep(i, 3) {
        sum += bingo[i][i];
    }
    if (sum == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    sum = 0;
    rep(i, 3) {
        sum += bingo[2 - i][i];
    }
    if (sum == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}