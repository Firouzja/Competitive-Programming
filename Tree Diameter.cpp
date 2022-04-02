#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n;
vector<int> adj[MAXN];
int ans = 0;

void dfs(int node, int prev, int cur) {
  ans = max(ans, cur);
  for (auto u : adj[node]) {
	if (u != prev) {
	  dfs(u, node, cur + 1);
	}
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
	int a, b;
	cin >> a >> b;
	a--, b--;
    adj[a].push_back(b);
	adj[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
	dfs(i, -1, 0);
  }
  cout << ans << '\n';
}