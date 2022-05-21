#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 150000;

vector<int> adj[MAX_N];
int comp[MAX_N];
int cnt[MAX_N+1];

void dfs(int v, int c) {
  comp[v] = c;
  cnt[c]++;
  for (auto u : adj[v])
    if (!comp[u])
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
  for (int i = 0; i < n; i++) {
    if (!comp[i]) {
      dfs(i, ++c);
    }
  }
  for (int i = 0; i < n; i++) {
    if (cnt[comp[i]]-1 != adj[i].size()) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}