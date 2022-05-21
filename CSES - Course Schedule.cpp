#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+1;

vector<int> adj[MAX_N];
bool vis[MAX_N];
vector<int> ans;

void dfs(int v) {
  vis[v] = true;
  for (auto u : adj[v])
    if (!vis[u])
      dfs(u);
  ans.push_back(v);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    adj[--u].push_back(--v);
  }
  for (int i = 0; i < n; i++) 
    if (!vis[i])
      dfs(i);
  reverse(ans.begin(), ans.end());
  vector<int> index(n);
  for (int i = 0; i < n; i++) index[ans[i]] = i;
  for (int v = 0; v < n; v++) for (auto u : adj[v]) if (index[u] <= index[v]) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  for (int i : ans)
    cout << i+1 << ' ';
  return 0;
}
