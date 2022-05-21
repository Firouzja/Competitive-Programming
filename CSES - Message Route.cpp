#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
const int INF = INT_MAX;

vector<vector<int>> adj(MAX_N);
vector<int> dist(MAX_N, -1);
vector<int> par(MAX_N);
queue<int> q;

int n, m;
bool good;

void bfs(int s) {
  dist[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (auto u : adj[v]) if (dist[u] == -1) {
      q.push(u);
      dist[u] = dist[v]+1;
      par[u] = v;
      if (u == n-1) {
        good = true;
        return;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bfs(0);
  if (good) {
    vector<int> ans;
    int i = n-1;
    while (true) {
      ans.push_back(i);
      i = par[i];
      if (i == 0) break;
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int j : ans) cout << j+1 << ' ';
    cout << "\n";
  } else {
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}
