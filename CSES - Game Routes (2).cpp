#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<int> edge[MAX_N];
vector<int> backEdge[MAX_N];
int inDegree[MAX_N];
int dp[MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    edge[u].push_back(v);
    backEdge[v].push_back(u);
    inDegree[v]++;
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }
  dp[0] = 1;
  while (!q.empty()) {
    int node = q.front(); q.pop();
    for (auto nxt : edge[node]) {
      --inDegree[nxt];
      if (!inDegree[nxt]) 
        q.push(nxt);
    }
    for (auto prv : backEdge[node]) {
      dp[node] += dp[prv];
      dp[node] %= MOD;
    }
  }
  cout << dp[n-1] << "\n";
  return 0;
}
