#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int N = 1 << n;

    vector<int> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];

    map<int, int, greater<int>> mp;

    for (int i = 0; i < N; i++) mp[s[i]]++;

    priority_queue<int> pq;
    pq.push(N);

    for (auto m : mp) {
        if (pq.size() < m.second) {
            cout << "No" << endl;
            return 0;
        }

        vector<int> buf;
        for (int _ = 0; _ < m.second; _++) {
            buf.push_back(pq.top());
            pq.pop();
        }

        for (int e : buf) {
            e /= 2;
            while (e > 0) {
                pq.push(e);
                e /= 2;
            }
        }
    }

    cout << "Yes" << endl;
}
