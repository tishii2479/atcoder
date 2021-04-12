#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
struct Ad {
    struct Space {
        /*
        (a, d)   (c, d)
         (a, b)   (c, b)
        */
        int a, b, c, d;
        int area() {
            return (c - a) * (d - b);
        }
        void output() {
            printf("%d %d %d %d\n", a, b, c, d);
        }
    };
    int x, y, r;
    Space space;
    // siはriに近いほど良いスコアになる
    double calc_satisfaction() {
        double x = 1.0 - (double)min(space.area(), r) / max(space.area(), r);
        return 1.0 - x * x;
    }
};
void input();
void solve();
void output();
int calc_score();
int N;
vector<Ad> ad;
int main() {
    input();
    solve();
    // cout << calc_score() << endl;
    output();
}
void solve() {
    vector<int> idx(N);
    for (int i = 0; i < N; i++)
        idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return ad[a].r < ad[b].r;
    });
    for (int i : idx) {
        ad[i].space.a = ad[i].x;
        ad[i].space.c = ad[i].x + 1;
        ad[i].space.b = ad[i].y;
        ad[i].space.d = ad[i].y + 1;
    }
}
void output() {
    for (int i = 0; i < N; i++)
        ad[i].space.output();
}
void input() {
    cin >> N;
    ad.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        ad[i] = {x, y, r};
    }
}
int calc_score() {
    double sum = 0;
    for (int i = 0; i < N; i++)
        sum += ad[i].calc_satisfaction();
    sum *= (double)1e9 / N;
    return round(sum);
}