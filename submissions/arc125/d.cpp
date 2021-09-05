#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    atcoder::fenwick_tree<atcoder::modint998244353> tree(n + 1);
    vector<int> pre(n + 1, 0);
    tree.add(0, 1);
    for (int i = 0; i < n; i++) {
        int previous = pre[a[i]];
        tree.add(i + 1, tree.sum(previous, i + 1));
        if (previous) tree.add(previous, -tree.sum(previous, previous + 1));
        pre[a[i]] = i + 1;
    }

    cout << (tree.sum(0, n + 1) - 1).val() << endl;
}
