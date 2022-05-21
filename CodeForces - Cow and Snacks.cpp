#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
bool vis[MAX_N];

void dfs(int v) {
  vis[v] = true;
  for (auto u : adj[v])
    if (!vis[u])
      dfs(u);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int m, n;
  cin >> m >> n;
  for (int i = 0, u, v; i < n; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v); 
    adj[v].push_back(u);
  }
  int good = m;
  for (int i = 0; i < m; i++) {
    if (!vis[i]) {
      dfs(i);
      --good;
    }
  }
  cout << n - good << "\n";
  return 0;
}
