#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;
const int MOD = (int)1e9 + 7;

int dp[1 << MAX_N][MAX_N];
vector<int> adj[MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
	  int u, v; cin >> u >> v; 
	  adj[--v].push_back(--u);
  }
  dp[1][0] = 1;
  for (int mask = 2; mask < (1 << n); mask++) {
    if ((mask & (1 << (n-1))) && mask != (1 << n) - 1) continue;
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) == 0) continue;
      for (int u : adj[i]) {
        if (mask & (1 << u)) {
          dp[mask][i] += dp[mask - (1 << i)][u];
          dp[mask][i] %= MOD;
        }
      }
    }
  }
  cout << dp[(1<<n)-1][n-1] << '\n';
}
