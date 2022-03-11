#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 110;
int n, m, a, b;
bool adj[MAX_N][MAX_N];
bool visited[MAX_N];
vector<pair<int,int>> edges;

void dfs(int node) {
  visited[node] = true;
  for (int i = 0; i < n; i++) {
	if (adj[node][i] && !visited[i]) 
	  dfs(i);
  }
}

bool check() {
  for (auto e : edges) {
	adj[e.first][e.second] = false;
	adj[e.second][e.first] = false;
	memset(visited, false, sizeof(visited));
	dfs(0);
	for (int i = 0; i < n; i++) {
	  if (!visited[i])
	    return false;
	}
	adj[e.first][e.second] = true;
	adj[e.second][e.first] = true;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  memset(adj, false, sizeof(adj));
  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
	adj[a][b] = true;
	adj[b][a] = true;
	edges.push_back(make_pair(a, b));
  }
  cout << (check() ? "No" : "Yes") << "\n";
}
