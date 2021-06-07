#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;
const int N = 30;
const int initial_value = 5000;
int h[N][N];
int v[N][N];
pair<int, int> unit[4] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

string direction = "RLDU";

struct Query {
    int sx, sy, tx, ty;
};

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            h[i][j] = v[i][j] = initial_value;
}

Query input_query() {
    Query q;
    cin >> q.sy >> q.sx >> q.ty >> q.tx;
    return q;
}

int cost(int ax, int ay, int bx, int by) {
    assert(ax == bx or ay == by);
    if (ax == bx) {
        return v[min(ay, by)][ax];
    } else {
        return h[ay][min(ax, bx)];
    }
}

bool is_invalid(int x, int y) {
    return (x < 0 or y < 0 or x >= N or y >= N);
}

void output_dist(vector<vector<int>> &dist) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            fprintf(stderr, "%100d ", dist[i][j]);
        cerr << endl;
    }
}

void dijkstra(vector<vector<int>> &dist, int sx, int sy) {
    // { dist, { x, y } }
    using P = pair<int, pair<int, int>>;
    dist[sy][sx] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, {sx, sy}});
    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first, x = p.second.first, y = p.second.second;
        if (d > dist[y][x]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + unit[i].first, ny = y + unit[i].second;
            if (is_invalid(nx, ny)) continue;
            if (dist[y][x] + cost(x, y, nx, ny) >= dist[ny][nx]) continue;
            dist[ny][nx] = dist[y][x] + cost(x, y, nx, ny);
            pq.push({dist[ny][nx], {nx, ny}});
        }
    }
}

void update_cost(int ax, int ay, int bx, int by, int cost) {
    assert(ax == bx or ay == by);
    int cx, cy;
    if (ax == bx) {
        v[min(ay, by)][ax] = (cost + v[min(ay, by)][ax]) / 2;
    } else {
        h[ay][min(ax, bx)] = (cost + h[ay][min(ax, bx)]) / 2;
    }
}

string find_shortest_path(Query q) {
    vector<vector<int>> dist(N, vector<int>(N, inf));
    dijkstra(dist, q.sx, q.sy);

    int cur_x = q.tx, cur_y = q.ty;
    string path = "";
    while (cur_x != q.sx or cur_y != q.sy) {
        for (int i = 0; i < 4; i++) {
            int prev_x = cur_x - unit[i].first, prev_y = cur_y - unit[i].second;
            if (is_invalid(prev_x, prev_y)) continue;
            if (dist[prev_y][prev_x] + cost(cur_x, cur_y, prev_x, prev_y) == dist[cur_y][cur_x]) {
                cur_x = prev_x;
                cur_y = prev_y;
                path += direction[i];
                break;
            }
            assert(i != 3);
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

void change_weight(Query q, string path, int result) {
    int cur_x = q.sx, cur_y = q.sy;
    int cost_per_unit = result / path.length();
    int cur = 0;
    while (cur_x != q.tx or cur_y != q.ty) {
        for (int i = 0; i < 4; i++) {
            if (direction[i] != path[cur]) continue;
            int next_x = cur_x + unit[i].first, next_y = cur_y + unit[i].second;
            assert(!is_invalid(next_x, next_y));
            update_cost(cur_x, cur_y, next_x, next_y, cost_per_unit);
            cur_x = next_x, cur_y = next_y;
        }
        cur++;
    }
}

int main() {
    init();
    for (int i = 0; i < 1000; i++) {
        Query q = input_query();
        string path = find_shortest_path(q);
        cout << path << endl;
        cout << flush;
        int result;
        cin >> result;
        change_weight(q, path, result);
    }
}
