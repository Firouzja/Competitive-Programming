#include <bits/stdc++.h>
#define sz(v) ((int)v.size())
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> dist;

void bfs(int s) {
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (auto u : adj[v]) if (dist[u] == -1) {
      dist[u] = dist[v]+1;
      q.push(u);
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> cnt0, cnt1;
  adj = vector<vector<int>>(n);
  dist = vector<int>(n, -1);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bfs(0);
  for (int i = 0; i < n; i++) {
    if (dist[i] & 1) cnt1.push_back(i);
    else cnt0.push_back(i);
  }
  if (sz(cnt0) < sz(cnt1)) {
    cout << sz(cnt0) << "\n";
    for (int i : cnt0) cout << i+1 << ' ';
  } else {
    cout << sz(cnt1) << "\n";
    for (int i : cnt1) cout << i+1 << ' ';
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
