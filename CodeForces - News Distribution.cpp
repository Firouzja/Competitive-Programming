#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;

vector<int> adj[MAX_N+1];
int comp[MAX_N+1];
int ans[MAX_N+1];

int n, m;
int color = 0;

int dfs(int node) {
  if (comp[node]) return 0;
  comp[node] = color;
  int ret = (node < n ? 1 : 0);
  for (auto nxt : adj[node])
    ret += dfs(nxt);
  return ret;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
	  int k; cin >> k;
	  while (k--) {
	    int x; cin >> x; x--;
        adj[x].push_back(i+n);
        adj[i+n].push_back(x);
	  }
  }
  for (int i = 0; i < n; i++) {
	if (!comp[i]) {
      color++;
	  ans[color] = dfs(i);
    }
    cout << ans[comp[i]] << ' ';
  }
  cout << '\n';
  return 0;
}
