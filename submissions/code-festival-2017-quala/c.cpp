#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int h, w;
    cin >> h >> w;
    vector<int> cnt(26, 0);
    for (int i = 0; i < h * w; i++) {
        char c;
        cin >> c;
        cnt[c - 'a']++;
    }
    if (h % 2 == 0 and w % 2 == 0) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 4 != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    } else if (h % 2 != w % 2) {
        int cnt2 = 0;
        if (h % 2 == 1) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] % 4 != 0) {
                    if (cnt[i] % 2 == 0) {
                        cnt2++;
                    } else {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
            if (cnt2 <= w / 2) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] % 4 != 0) {
                    if (cnt[i] % 2 == 0) {
                        cnt2++;
                    } else {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
            if (cnt2 <= h / 2) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    } else if (h % 2 == 1 and w % 2 == 1) {
        int cnt2 = 0;
        int cnt1 = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 4 != 0) {
                if (cnt[i] % 2 == 0) {
                    cnt2++;
                } else {
                    cnt1++;
                    if (cnt1 > 1) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
        if (cnt2 <= w / 2 + h / 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}