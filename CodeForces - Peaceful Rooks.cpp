#include <bits/stdc++.h>
#define sz(v) ((int)v.size())

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int v) {
  vis[v] = true;
  for (auto u : adj[v])
    if (!vis[u])
      dfs(u);
}

void solve() {
  int n, m, cnt1 = 0, cnt2 = 0;
  cin >> n >> m;
  adj = vector<vector<int>>(n);
  vis = vector<bool>(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    if (u == v) {
      cnt1++;
      continue;
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) if (!vis[i]) {
    ++cnt2;
    dfs(i);
  }
  cout << (m - cnt1 * 2) + cnt2 - (n - m) << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
