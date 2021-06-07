#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    vector<pair<ll, int>> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first >> y[i].first;
        x[i].second = y[i].second = i;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<pair<ll, pair<int, int>>> cand;

    cand.push_back({abs(x[0].first - x[n - 1].first), {min(x[0].second, x[n - 1].second), max(x[0].second, x[n - 1].second)}});
    cand.push_back({abs(x[1].first - x[n - 1].first), {min(x[1].second, x[n - 1].second), max(x[1].second, x[n - 1].second)}});
    cand.push_back({abs(x[0].first - x[n - 2].first), {min(x[0].second, x[n - 2].second), max(x[0].second, x[n - 2].second)}});
    cand.push_back({abs(y[0].first - y[n - 1].first), {min(y[0].second, y[n - 1].second), max(y[0].second, y[n - 1].second)}});
    cand.push_back({abs(y[1].first - y[n - 1].first), {min(y[1].second, y[n - 1].second), max(y[1].second, y[n - 1].second)}});
    cand.push_back({abs(y[0].first - y[n - 2].first), {min(y[0].second, y[n - 2].second), max(y[0].second, y[n - 2].second)}});

    sort(cand.begin(), cand.end(), greater<pair<ll, pair<int, int>>>());

    if (cand[0].second == cand[1].second) {
        cout << cand[2].first << endl;
    } else {
        cout << cand[1].first << endl;
    }
}
