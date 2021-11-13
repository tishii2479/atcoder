#include <bits/stdc++.h>
using namespace std;

struct S {
    int left = -1;
    int right = -1;
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<S> train(n + 1);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;

            train[x].right = y;
            train[y].left = x;
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;

            train[x].right = -1;
            train[y].left = -1;
        } else {
            int x;
            cin >> x;

            // go to left;
            int cur = x;
            while (train[cur].left != -1) cur = train[cur].left;

            vector<int> v;
            v.push_back(cur);

            while (train[cur].right != -1) {
                cur = train[cur].right;
                v.push_back(cur);
            }

            cout << v.size() << " ";
            for (int e : v) cout << e << " ";
            cout << endl;
        }
    }
}
