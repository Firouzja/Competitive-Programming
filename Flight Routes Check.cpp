#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 10;
int n, m;
vector<int> adj[MAX_N][2];
bool visited[MAX_N];

void dfs(int v, int x) {
  visited[v] = true;
  for (int u : adj[v][x]) {
	if (!visited[u])
	  dfs(u, x);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  while (m--) {
	int a, b;
	cin >> a >> b;
	a--, b--;
	adj[a][0].push_back(b);
	adj[b][1].push_back(a);
  }
  dfs(0, 0);
  for (int i = 0; i < n; i++) {
	if (!visited[i]) {
	  cout << "NO\n";
	  cout << 1 << ' ' << i + 1 << '\n';
	  return 0;
	}
  }
  memset(visited, false, sizeof(visited));
  dfs(0, 1);
  for (int i = 0; i < n; i++) {
	if (!visited[i]) {
	  cout << "NO\n";
	  cout << i + 1 << ' ' << 1 << '\n';
	  return 0;
	}
  }
  cout << "YES\n";
}