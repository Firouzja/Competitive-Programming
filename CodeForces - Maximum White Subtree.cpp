#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5;

vector<int> adj[MAX_N];
int arr[MAX_N];
int dp1[MAX_N];
int dp2[MAX_N];

void dfs1(int v = 0, int p = -1) {
  dp1[v] = arr[v];
  for (auto u : adj[v]) {
    if (u == p) continue;
    dfs1(u, v);
    dp1[v] += max(0, dp1[u]);
  }
}

void dfs2(int v = 0, int p = -1) {
  dp2[v] = dp1[v];
  for (auto u : adj[v]) {
    if (u == p) continue;
    dp1[v] -= max(0, dp1[u]);
    dp1[u] += max(0, dp1[v]);
    dfs2(u, v);
    dp1[u] -= max(0, dp1[v]);
    dp1[v] += max(0, dp1[u]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0, x; i < n; i++) {
    cin >> x; 
    arr[i] = (x ? 1 : -1);
  }
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1();
  dfs2();
  for (int i = 0; i < n; i++) cout << dp2[i] << ' ';
  return 0;
}