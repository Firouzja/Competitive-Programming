#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5001;
int n, q;
vector<pair<int,int>> adj[MAXN];
int vis[MAXN];
int k, v, ans;

void dfs(int node) {
  vis[node] = true;
  for (auto x : adj[node]) {
	if (!vis[x.first] && x.second >= k) {
	  ans++;
	  dfs(x.first);
	}
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
	int a, b, r;
	cin >> a >> b >> r;
	adj[a].push_back(make_pair(b, r));
	adj[b].push_back(make_pair(a, r));
  }
  while (q--) {
	cin >> k >> v;
	ans = 0;
	memset(vis, false, sizeof(vis));
	dfs(v);
	cout << ans << '\n';
  }
}
