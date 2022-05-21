#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MAX_N = 3e5;

int n, x, y;
vector<int> adj[MAX_N];
int subtree[MAX_N];
bool chk[MAX_N];

int dfs(int v, int p) {
  subtree[v] = 1;
  if (v == x) chk[v] = true;
  for (auto u : adj[v]) {
    if (u != p) {
      subtree[v] += dfs(u, v);
      chk[v] |= chk[u];
    }
  }
  return subtree[v];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> x >> y; x--, y--;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(y, -1);
  int v;
  for (int u : adj[y]) {
    if (chk[u]) {
      v = u;
      break;
    }
  }
  cout << n*(n-1) - (subtree[y]-subtree[v])*subtree[x] << '\n';
  return 0;
}
