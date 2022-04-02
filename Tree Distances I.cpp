#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n;
int dist[2][MAXN];
vector<int> adj[MAXN];

int dfs(int u, int p, int d, int i) {
  dist[i][u] = d;
  int opt = -1;
  for (int v : adj[u]) {
	if (v != p) {
	  int x = dfs(v, u, d+1, i);
	  if (opt == -1 || dist[i][x] > dist[i][opt])
	    opt = x;
	}
  }
  return opt == -1 ? u : opt;
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
  int mxNode = dfs(0, 0, 0, 0);
  int mxNode2 = dfs(mxNode, mxNode, 0, 0);
  dfs(mxNode2, mxNode2, 0, 1);
  for (int i = 0; i < n; i++) {
	cout << max(dist[0][i], dist[1][i]) << ' ';
  }
  cout << '\n';
}
