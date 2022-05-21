#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const int MAX_N = 2005;

struct Edge {
  int u, v, w;
};

bool cmp (const Edge& a, const Edge& b) {
  return a.w < b.w;
}

vector<Edge> edges;
int par[MAX_N*MAX_N];
int siz[MAX_N*MAX_N];

int xMax, yMax, n, m;
ll ans = 0;

void make(int v) {
  par[v] = v;
  siz[v] = 1;
}

int find(int v) {
  return v == par[v] ? v : par[v] = find(par[v]);
}

bool unite(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return false;
  if (siz[u] < siz[v]) swap(u, v);
  par[v] = u;
  siz[u] += siz[v];
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> xMax >> yMax >> n >> m;
  vector<int> x(n+1, 0), y(m+1, 0);
  for (int i = 1; i <= n; i++)
    cin >> x[i];
  for (int i = 1; i <= m; i++)
    cin >> y[i];
  x.push_back(xMax);
  y.push_back(yMax);
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) {
    int id = i*(n+1) + j;
    make(id);
    if (i != m) {
      int tmp = y[i+1] - y[i];
      edges.push_back({id, id+n+1, tmp});
    }
    if (j != n) {
      int tmp = x[j+1] - x[j];
      edges.push_back({id, id+1, tmp});
    }
  }
  sort(edges.begin(), edges.end(), cmp);
  for (auto [u, v, w] : edges) {
    if (unite(u, v)) {
      ans += w;
    }
  }
  cout << ans << "\n";
  return 0;
}
