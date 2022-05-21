#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2001;

vector<int> adj[MAX_N];
int comp[MAX_N];
int cnt[MAX_N];
bool bad[MAX_N];
bool vis[MAX_N];

void dfs(int v, int c) {
  if (vis[v]) return;
  vis[v] = true;
  cnt[c]++;
  comp[v] = c;
  for (auto u : adj[v])
    dfs(u, c);  
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int c = 0;
  for (int i = 0; i < n; i++)
    if (!vis[i])
      dfs(i, ++c);
  cin >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    if (comp[u] == comp[v])
      bad[comp[u]] = true;
  }
  int ans = 0;
  for (int i = 0; i <= c; i++)
    if (!bad[i]) 
      ans = max(ans, cnt[i]);
  cout << ans << '\n';
  return 0;
}
