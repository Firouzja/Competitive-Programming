#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N];
bool vis[MAX_N];
vector<int> ord;
int dp[MAX_N];

int n, m;

void dfs(int v) {
  vis[v] = true;
  for (auto u : adj[v])
    if (!vis[u])
      dfs(u);
  ord.push_back(v);
}

void topological_sort() {
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  reverse(ord.begin(), ord.end());
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;  
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; adj[--u].push_back(--v);
  }
  topological_sort();
  dp[0] = 1;
  for (int v : ord) {
    for (auto u : adj[v]) {
      dp[u] += dp[v];
      dp[u] %= MOD;
    }
    if (v == n-1) break;
  }
  cout << dp[n-1] << "\n";
  return 0;
}
