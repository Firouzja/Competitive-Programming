#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const int MAX_N = 1e5; 

vector<pair<int,int>> adj[MAX_N];

ll maxPath = 0, tot = 0;

void dfs (int v, int p, ll cur) {
  maxPath = max(maxPath, cur);
  for (auto [u, w] : adj[v])
    if (u != p)
      dfs(u, v, cur+w);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1, u, v, w; i < n; i++) {
    cin >> u >> v >> w; u--, v--;
    adj[u].push_back({v, w}); 
    adj[v].push_back({u, w});
    tot += 2*w;
  }
  dfs(0, 0, 0);
  cout << tot - maxPath << "\n";
  return 0;
}