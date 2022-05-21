#include <bits/stdc++.h>
#define int int64_t

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e5;

vector<int> adj[MAX_N];
int comp[MAX_N];
int cnt[MAX_N];

int binpow(int x, int n) {
  x %= MOD;
  int res = 1;
  while (n > 0) {
    if (n & 1) 
      res = res * x % MOD;
    x = x * x % MOD;
    n /= 2;
  }
  return res;
}

void dfs(int v, int p, int c) {
  comp[v] = c;
  cnt[c]++;
  for (auto u : adj[v])
    if (u != p)
      dfs(u, v, c);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 0, u, v; i < n-1; i++) {
	  bool w; cin >> u >> v >> w; u--, v--;
    if (w) continue;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
  }
  int c = 0;
  for (int i = 0; i < n; i++) 
    if (!comp[i])
      dfs(i, -1, ++c);
  int ans = binpow(n, k);
  for (int i = 1; i <= c; i++) {
    ans -= binpow(cnt[i], k);
    ans += MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
