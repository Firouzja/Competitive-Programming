#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

bool has[MAX_N];
vector<int> adj[MAX_N];

int n, m;
int ans = 0;

void dfs(int node, int prv, int cur) {
  int newCur = (has[node] ? cur+1 : 0);
  if (newCur > m) return;
  if (adj[node].size() == 1 && node != 0) {
    ++ans;
    return;
  }
  for (auto nxt : adj[node]) 
	if (nxt != prv) 
	  dfs(nxt, node, newCur);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> has[i];
  for (int i = 0, u, v; i < n-1; i++) {
	cin >> u >> v; --u, --v;
	adj[u].push_back(v);
	adj[v].push_back(u);
  }
  dfs(0, 0, 0);
  cout << ans << '\n';
  return 0;
}
