#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+1;

vector<int> adj[MAX_N];
bool vis[MAX_N];
vector<pair<int,int>> comps;
int mxNode, mnNode;

void dfs(int v) {
  if (vis[v]) return;
  vis[v] = true;
  mxNode = max(mxNode, v);
  mnNode = min(mnNode, v);
  for (auto u : adj[v])
    dfs(u);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      mnNode = mxNode = i;
      dfs(i);
      comps.push_back({mnNode, mxNode});
    }
  }
  int curEnd = -1;
  int ans = 0;
  for (auto p : comps) {
    if (p.first <= curEnd) 
      ++ans;
    curEnd = max(curEnd, p.second);
  }
  cout << ans << "\n";
  return 0;
}
