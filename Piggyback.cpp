#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const int MAX_N = 40010;

vector<vector<int>> adj(MAX_N);

int A, B, AB, N, M;

vector<ll> getDist(int s) {
  vector<ll> dist(MAX_N, -1);
  queue<int> q;
  dist[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (auto u : adj[v]) if (dist[u] == -1) {
      dist[u] = dist[v]+1;
      q.push(u);
    }
  }
  return dist;
}

int main() {
  freopen("piggyback.in", "r", stdin);
  freopen("piggyback.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> A >> B >> AB >> N >> M;
  for (int i = 0, u, v; i < M; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<ll> distA = getDist(0);
  vector<ll> distB = getDist(1);
  vector<ll> distAB = getDist(N-1);
  ll ans = 1e18;
  for (int i = 0; i < N; i++) {
    ans = min(ans, distA[i]*A+distB[i]*B+distAB[i]*AB);
  }
  cout << ans << "\n";
  return 0;
}