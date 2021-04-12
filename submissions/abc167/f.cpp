#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
vector<string> s;
bool solve() {
    vector<pair<ll, ll>> plus, minus;
    for (ll i = 0; i < n; i++) {
        ll diff = 0;
        ll worst = 0;
        for (ll j = 0; j < s[i].size(); j++) {
            if (s[i][j] == '(')
                diff++;
            else
                diff--;
            worst = min(worst, diff);
        }
        if (diff >= 0)
            plus.push_back({worst, diff});
        else
            minus.push_back({worst, diff});
    }
    sort(plus.begin(), plus.end(), greater<pair<int, int>>());
    sort(minus.begin(), minus.end(), [&](pair<ll, ll> a, pair<ll, ll> b) {
        return a.second - a.first > b.second - b.first;
    });
    ll cur = 0;
    for (auto p : plus) {
        // cout << p.first << " " << p.second << endl;
        if (cur + p.first < 0)
            return false;
        cur += p.second;
    }
    for (auto p : minus) {
        // cout << p.first << " " << p.second << endl;
        if (cur + p.first < 0)
            return false;
        cur += p.second;
    }
    return (cur == 0);
}
int main() {
    cin >> n;
    s.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> s[i];
    cout << (solve() ? "Yes" : "No") << endl;
}