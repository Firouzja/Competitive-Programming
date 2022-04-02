#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 1;
int n;
vector<int> edges[MAXN];
bool vis[MAXN];

void dfs(int node) {
  vis[node] = true;
  for (int u : edges[node]) {
	if (!vis[u]) {
	  dfs(u);
	}
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
	int x;
	cin >> x;
	edges[x].push_back(i);
	edges[i].push_back(x);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
	if (!vis[i]) {
	  ans++;
	  dfs(i);
	}
  }
  cout << ans << '\n';
}
