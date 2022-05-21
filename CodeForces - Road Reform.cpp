#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_N = 2e5+1;

struct Edge { 
  int u, v, w;
};

int par[MAX_N];

void make(int v) {
  par[v] = v;
}

int find(int v) {
  return v == par[v] ? v : par[v] = find(par[v]); 
}

bool unite(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return false;
  par[v] = u;
  return true;
}

bool cmp (const Edge& a, const Edge& b) {
  return a.w < b.w;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) make(i);
  vector<Edge> edges;
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w; u--, v--;
    edges.push_back({u, v, w});
  }
  sort(edges.begin(), edges.end(), cmp);
  ll ans = 0;
  for (auto [u, v, w] : edges) {
    if (unite(u, w)) {
      ans += max(0, w-k);
    }
  } 
  if (ans == 0) {
    ans = (int) 2e9;
    for (auto [u, v, w] : edges) {
      ans = min(ans, 0LL + abs(w-k));
    }
  }
  cout << edges[0].w << ' ' << edges[1].w << ' ' << edges[2].w << "\n"; 
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}