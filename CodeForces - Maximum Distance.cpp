#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

struct Edge {
  int u, v, w;
};

int par[MAX_N];
int cnt[MAX_N];
vector<Edge> edges;

int n, m, k;
int ans;

bool cmp(const Edge& a, const Edge& b) {
  return a.w < b.w;
}

void make(int v) {
  par[v] = v;
}

int find(int v) {
  return v == par[v] ? v : par[v] = find(par[v]);
}

bool unite(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return false;
  par[u] = v;
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0, x; i < k; i++) {
    cin >> x; 
    cnt[--x] = 1;
  }
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w; u--, v--;
    edges.push_back({u, v, w});
  }
  sort(edges.begin(), edges.end(), cmp);
  for (int i = 0; i < n; i++) make(i);
  for (auto &&[u, v, w] : edges) {
    if (unite(u, v)) {
      cnt[v] += cnt[u];
      if (cnt[find(u)] == k) {
        ans = w;
        break;
      }
    }
  }
  while (k--) {
    cout << ans << ' ';
  }
  cout << "\n";
  return 0;
}
