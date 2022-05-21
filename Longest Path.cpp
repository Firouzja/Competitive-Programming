#include <bits/stdc++.h>
using namespace std;

template <class T> void ckmax(T &a, const T &b) { a = max(a, b); }

int dfs(vector<vector<int>>& edges, vector<int>* ptr, int v) {
  int ret = -1;
  for (auto u : edges[v]) {
    if ((*ptr)[u] == -1)
      ckmax(ret, dfs(edges, ptr, u));
    else
      ckmax(ret, (*ptr)[u]);
  }
  return (*ptr)[v] = ret+1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0, u, v; i < m; i++) {
	  cin >> u >> v; adj[--u].push_back(--v);
  }
  vector<int> dp(m, -1);
  for (int i = 0; i < m; i++)  
    if (dp[i] == -1)
      dfs(adj, &dp, i);
  int ans = *max_element(dp.begin(), dp.end());
  cout << (ans==-1?0:ans) << '\n';
}
