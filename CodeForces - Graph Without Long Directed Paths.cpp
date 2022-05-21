#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

vector<int> adj[MAX_N];
bool vis[MAX_N];
int ord[MAX_N];
vector<int> par(MAX_N, -1);
bool bad = false;

void dfs(int v) {
  vis[v] = true;
  for (auto u : adj[v]) {
    if (par[u] == par[v]) 
      bad = true;
    par[u] = 1-par[v];
  }
  for (auto u : adj[v]) 
    if (!vis[u])
      dfs(u);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ord[i] = u;
  }
  par[0] = 0; dfs(0);
  if (bad) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
      cout << par[ord[i]];
    }
  }
  return 0;
}