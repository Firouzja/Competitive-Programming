#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const int MOD = 998244353;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
ll cnt[2];
bool bad;

ll binpow(ll a, ll b) {
  a %= MOD;
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void dfs(int v) {
  vis[v] = true;
  if (col[v] == 0) cnt[0]++;
  if (col[v] == 1) cnt[1]++;
  for (auto u : adj[v]) {
    if (col[u] == col[v]) bad = true;
    col[u] = 1-col[v];
  }
  for (auto u : adj[v])
    if (!vis[u])
      dfs(u);
}

void solve() {
  int n, m;
  cin >> n >> m;
  adj = vector<vector<int>>(n+1);
  vis = vector<bool>(n+1);
  col = vector<int>(n+1, -1);
  cnt[0] = 0, cnt[1] = 0;
  bad = false;
  ll ans = 1;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) if (!vis[i]) {
    cnt[0] = 0, cnt[1] = 0;
    col[i] = 0;
    dfs(i);
    ans *= binpow(2, cnt[0]) + binpow(2, cnt[1]);
    ans = (ans%MOD+MOD)%MOD;
  }
  if (bad) {
    cout << "0\n";
  } else {
    cout << ans << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}