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
    vector<double> x(n);
    vector<double> y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(i);
    double sum = 0;
    do {
        double s = 0;
        for (int i = 0; i < n - 1; i++) {
            double b = (x[v[i + 1]] - x[v[i]]) * (x[v[i + 1]] - x[v[i]]) + (y[v[i + 1]] - y[v[i]]) * (y[v[i + 1]] - y[v[i]]);
            double dist = sqrt(b);
            s += dist;
        }
        sum += s;
    } while (next_permutation(v.begin(), v.end()));
    // cout << sum << endl;
    int kaijo = 1;
    for (int i = 1; i <= n; i++) {
        kaijo *= i;
    }
    printf("%.15lf\n", sum / kaijo);
}