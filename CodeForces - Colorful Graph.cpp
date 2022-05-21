#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
bool vis [MAX_N];
int color [MAX_N];
unordered_set<int> cnt[MAX_N+1];

void dfs(int v) {
  if (vis[v]) return;
  vis[v] = true;
  for (auto u : adj[v]) {
    if (color[u] != color[v])
      cnt[color[v]].insert(color[u]);
    dfs(u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int minColor = 1000000, maxColor = 0;
  for (int i = 0; i < n; i++) {
    cin >> color[i];
    minColor = min(minColor, color[i]);
    maxColor = max(maxColor, color[i]);
  }
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
  int mx = 0, ans = 1;
  for (int i = maxColor; i >= minColor; i--) {
    if (cnt[i].size() >= mx) {
      ans = i;
      mx = cnt[i].size();
    }
  }
  cout << ans << '\n';
  return 0;
}
