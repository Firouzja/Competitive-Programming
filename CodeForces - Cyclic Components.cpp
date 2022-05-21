#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

vector<int> adj[MAX_N];
int deg[MAX_N];
bool vis[MAX_N];
vector<int> comp;

void dfs(int v) {
  vis[v] = true;
  comp.push_back(v);
  for (auto to : adj[v])
    if (!vis[to])
      dfs(to);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
	  cin >> u >> v; u--, v--;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      comp.clear();
      dfs(i);
      bool ok = true;
      for (auto v : comp) ok &= (deg[v] == 2);
      ans += ok;
    }
  }
  cout << ans << '\n';
}