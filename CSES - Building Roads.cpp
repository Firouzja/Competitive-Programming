#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+1;

vector<int> adj[MAX_N];
int comp[MAX_N];
int rep[MAX_N];

int n, m;
int c;

void dfs(int v) {
  comp[v] = c;
  for (auto u : adj[v]) if (!comp[u])
    dfs(u);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) if (!comp[i]) {
    c++;
    rep[c] = i;
    dfs(i);
  }
  cout << c-1 << "\n";
  for (int i = 1; i < c; i++) {
    cout << rep[i]+1 << ' ' << rep[i+1]+1 << "\n";
  }
  return 0;
}
