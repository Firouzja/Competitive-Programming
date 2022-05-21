#include <bits/stdc++.h>
using namespace std;

int n, m, c;
vector<vector<int>> dp(1001, vector<int>(1001, -1));
vector<int> adj[1001];
int gain[1001];
int ans = 0;

int main() {
  freopen("time.in", "r", stdin);
  freopen("time.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++)
    cin >> gain[i];
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; 
    adj[--u].push_back(--v);
  }
  dp[0][0] = 0;
  for (int t = 0; t < 1000; t++)
    for (int i = 0; i < n; i++) 
      if (dp[i][t] != -1) 
        for (int u : adj[i]) 
          dp[u][t+1] = max(dp[u][t+1], dp[i][t]+gain[u]);
  for (int i = 0; i < 1001; i++) 
    ans = max(ans, dp[0][i] - c*i*i);
  cout << ans << '\n';
}
