#include <bits/stdc++.h>
#define sz(v) (int)v.size();

using namespace std;

const int MAX_N = 50000+10;
const int MAX_M = 500+10;

vector<int> adj[MAX_N+1];
int dp[MAX_M+1][MAX_N+1];

int n, k;
int64_t ans = 0;

void dfs(int v, int p) {
  for (int i = 1; i <= k; i++) dp[i][v] = 0;
  dp[0][v] = 1;
  for (auto u : adj[v]) {
    if (u == p) continue;
    dfs(u, v);
    for (int j = 1; j <= k; j++) ans += 1LL * dp[j-1][u] * dp[k-j][v];
    for (int j = 1; j <= k; j++) dp[j][v] += dp[j-1][u];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);
  cout << ans << "\n";
  return 0;
}
