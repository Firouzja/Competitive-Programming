#include <bits/stdc++.h>
#define sz(v) ((int)v.size())

using namespace std;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
char vis[MAX_N];
vector<vector<int>> cycles;
vector<int> path;

void dfs(int v) {
  path.push_back(v);
  vis[v] = 1;
  for (auto u : adj[v]) {
    if (vis[u] == 2) continue;
    if (vis[u] == 1) {
      cycles.emplace_back();
      int id = sz(path)-1;
      while (path[id] != u)
        cycles.back().push_back(path[id--]);
      cycles.back().push_back(u);
    } else {
      dfs(u);
    }
  }
  path.pop_back();
  vis[v] = 2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    adj[--u].push_back(--v);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  if (!sz(cycles)) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  cycles[0].push_back(cycles[0][0]);
  reverse(cycles[0].begin(), cycles[0].end());
  cout << sz(cycles[0]) << "\n";
  for (auto v : cycles[0]) cout << v+1 << ' ';
  return 0;
}
