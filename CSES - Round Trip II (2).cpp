#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
char vis[MAX_N];
int par[MAX_N];
int cycleStart = -1, cycleEnd = 0;

void dfs(int v) {
  vis[v] = 1;
  for (auto u : adj[v]) {
    if (vis[u] == 2) continue;
    if (vis[u] == 1) {
      cycleStart = u;
      cycleEnd = v;
      return;
    } else {
      par[u] = v;
      dfs(u);
    }
  }
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
  for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
  if (cycleStart == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<int> ans;
    ans.push_back(cycleStart);
    for (int v = cycleEnd; v != cycleStart; v = par[v])
      ans.push_back(v);
    ans.push_back(cycleStart);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i : ans) cout << i+1 << ' ';
    cout << "\n";
  }
  return 0;
}
