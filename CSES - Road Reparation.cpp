#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const int MAX_N = 1e5;

int par[MAX_N];
int siz[MAX_N];

void make(int v) {
  par[v] = v;
  siz[v] = 1;
}

int find(int v) {
  return par[v] == v ? v : par[v] = find(par[v]);
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
  int n, m;
  cin >> n >> m;
  vector<tuple<int,int,int>> edges;
  for (int i = 0; i < n; i++) 
    make(i);
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w; u--, v--;
    edges.push_back({w, u, v});
  }
  sort(edges.begin(), edges.end());
  ll ans = 0;
  int cnt = 0;
  for (auto [w, u, v] : edges) {
    if (unite(u, v)) {
      ans += w;
      ++cnt;
    }
  }
  if (cnt != n-1) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << ans << "\n";
  }
  return 0;
}
