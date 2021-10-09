#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char a[110][110];
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    using P = pair<int, int>;
    vector<P> people;
    for (int i = 0; i < 2 * n; i++) {
        people.push_back({0, i});
    }

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            int l = people[2 * k].second, r = people[2 * k + 1].second;
            // aiko
            if (a[l][i] == a[r][i]) {
                continue;
            }
            if ((a[l][i] == 'G' and a[r][i] == 'C') or
                (a[l][i] == 'C' and a[r][i] == 'P') or
                (a[l][i] == 'P' and a[r][i] == 'G')) {
                // l win
                people[2 * k].first++;
            } else {
                // r win
                people[2 * k + 1].first++;
            }
        }

        sort(people.begin(), people.end(), [&](P a, P b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });
    }

    for (int i = 0; i < 2 * n; i++) {
        cout << people[i].second + 1 << endl;
    }
}
