#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+1;

vector<int> adj[MAX_N];
int dep[MAX_N];
int ans = 0;

void dfs1(int v, int p, int d) {
  dep[v] = d;
  for (auto u : adj[v]) 
    if (u != p)
      dfs1(u, v, d+1);
}

void dfs2(int v, int p, int d) {
  if (d >= dep[v]) return;
  ans = max(ans, dep[v]*2);
  for (auto u : adj[v])
    if (u != p)
      dfs2(u, v, d+1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, x;
  cin >> n >> x; x--;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(0, 0, 0);
  dfs2(x, x, 0);
  ans = max(ans, dep[x]*2);
  cout << ans << "\n";
  return 0;
}
