#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
bool vis[MAX_N];
vector<int> ord;

int n, m;
int cnt = 0;

void dfs1(int v) {
  vis[v] = true;
  for (auto u : adj[v])
    if (!vis[u])
      dfs1(u);
  ord.push_back(v);
}

void topological_sort() {
  for (int i = 0; i < n; i++) 
    if (!vis[i])
      dfs1(i);
  reverse(ord.begin(), ord.end());
}

void dfs2(int v) {
  vis[v] = true;
  cnt++;
  for (auto u : adj[v])
    if (!vis[u])
      dfs2(u);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
  }
  topological_sort();
  memset(vis, false, sizeof(vis));
  dfs2(ord.back());
  if (cnt == n) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
    for (int i = 0; i < n; i++) if (!vis[i]) {
      cout << i+1 << ' ' << ord.back()+1 << "\n";
      break;
    }
  }
  return 0;
}
