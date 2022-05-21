#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int MAX_N = 1e5;

int a[MAX_N];
vector<pair<ll,ll>> adj[MAX_N];
ll dep[MAX_N];
ll minDep[MAX_N];
bool chk[MAX_N];

void dfs1(int v, int p) {
  if (minDep[v] < dep[v] - a[v])
    chk[v] = true;
  minDep[v] = min(minDep[v], dep[v]);
  for (auto u : adj[v]) {
    if (u.second == p) continue;
    dep[u.second] = dep[v] + u.first;
    minDep[u.second] = min(minDep[u.second], minDep[v]);
    dfs1((ll)u.second, v);
  }
}

int dfs2(int v, int p) {
  if (chk[v]) return 0;
  int ret = 1;
  for (auto u : adj[v])
    if (u.second != p)
      ret += dfs2((ll)u.second, v);
  return ret;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) 
    minDep[i] = INT_MAX;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1, p, c; i < n; i++) {
    cin >> p >> c;
    adj[--p].push_back({c, i});
  }
  dfs1(0, 0);
  cout << n - dfs2(0, 0) << '\n';
  return 0;
}