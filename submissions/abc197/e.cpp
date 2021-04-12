#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int main() {
    const int N = 210000;
    int n;
    cin >> n;
    vector<ll> xs[N];
    for (int i = 0; i < n; i++) {
        ll x, c;
        cin >> x >> c;
        xs[c].push_back(x);
    }
    for (int i = 0; i < N; i++)
        sort(xs[i].begin(), xs[i].end());
    // pos, time
    pll cur1 = {0, 0}, cur2 = {0, 0};
    for (int i = 0; i < N; i++) {
        if (xs[i].size() == 0)
            continue;
        ll left = xs[i][0], right = xs[i][xs[i].size() - 1];
        pll nxt1, nxt2;
        nxt1.first = left, nxt2.first = right;
        // cur1
        if (cur1.first < right)
            nxt1.second = cur1.second + abs(cur1.first - right) * 2 + abs(cur1.first - left);
        else
            nxt1.second = cur1.second + abs(cur1.first - left);
        if (cur1.first > left)
            nxt2.second = cur1.second + abs(cur1.first - left) * 2 + abs(cur1.first - right);
        else
            nxt2.second = cur1.second + abs(cur1.first - right);
        // cur2
        if (cur2.first < right)
            nxt1.second = min(nxt1.second, cur2.second + abs(cur2.first - right) * 2 + abs(cur2.first - left));
        else
            nxt1.second = min(nxt1.second, cur2.second + abs(cur2.first - left));
        if (cur2.first > left)
            nxt2.second = min(nxt2.second, cur2.second + abs(cur2.first - left) * 2 + abs(cur2.first - right));
        else
            nxt2.second = min(nxt2.second, cur2.second + abs(cur2.first - right));
        cur1 = nxt1;
        cur2 = nxt2;
    }
    cout << min(abs(cur1.first) + cur1.second, abs(cur2.first) + cur2.second) << endl;
}