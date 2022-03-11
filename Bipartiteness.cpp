#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
int n;
long long c1 = 0, c2 = 0;
vector<vector<int>> edges(MAX);
bool vis[MAX];

void dfs(int node, bool color) {
  vis[node] = true;
  (color ? c1 : c2)++;
  for (int u : edges[node]) {
	if (!vis[u])
	  dfs(u, !color);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
	int a, b;
	cin >> a >> b;
	a--, b--;
    edges[a].push_back(b);
	edges[b].push_back(a);
  }
  memset(vis, false, sizeof(vis));
  dfs(0, 0);
  cout << c1*c2 - (n - 1) << '\n';
}
