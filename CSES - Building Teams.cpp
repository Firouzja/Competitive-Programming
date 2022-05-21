#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
int col[MAX_N];

bool bad;

void dfs(int v, int c) {
  col[v] = c;
  for (auto u : adj[v])
    if (col[u] && col[u] == c)
      bad = true;
  for (auto u : adj[v])
    if (!col[u])
      dfs(u, (c == 1 ? 2 : 1));
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
  for (int i = 0; i < n; i++) if (!col[i])
    dfs(i, 1);
  if (!bad) {
    for (int i = 0; i < n; i++)
      cout << col[i] << ' ';
    cout << "\n";
  } else {
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}
