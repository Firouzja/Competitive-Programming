#include <bits/stdc++.h>
#define sz(v) ((int)v.size())

using namespace std;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
char vis[MAX_N];
vector<int> path;
vector<int> tmp;
vector<int> ans;

int n, m, k;

void dfs(int v) {
  path.push_back(v);
  vis[v] = 1;
  for (auto u : adj[v]) {
    if (vis[u] == 2) continue;
    if (vis[u] == 1) {
      tmp.clear();
      int it = sz(path)-1;
      while (path[it] != u)
        tmp.push_back(path[it--]);
      tmp.push_back(u);
      if (sz(tmp) > k) {
        ans = tmp;
      }
    } else {
      dfs(u);
    }
  }
  path.pop_back();
  vis[v] = 2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  cout << sz(ans) << "\n";
  for (auto v : ans) cout << v+1 << ' ';
  return 0;
}
