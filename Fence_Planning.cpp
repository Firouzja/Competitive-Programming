#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;
int n, m, a, b, minX = MAX_N, minY = MAX_N, maxX = 0, maxY = 0;
vector<pair<int,int>> cows;
vector<int> adj[MAX_N];
vector<bool> visited(MAX_N);
set<int> components;  

void dfs(int node) {
  visited[node] = true;
  minX = min(minX, cows[node].first);
  minY = min(minY, cows[node].second);
  maxX = max(maxX, cows[node].first);
  maxY = max(maxY, cows[node].second);
  for (int u : adj[node]) {
	if (!visited[u])
	  dfs(u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  cows.resize(n + 1);
  for (int i = 1; i <= n; i++) 
	cin >> cows[i].first >> cows[i].second;
  for(int i = 0; i < m; i++) {
	cin >> a >> b;
	adj[a].push_back(b);
	adj[b].push_back(a);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
	if (!visited[i]) {
	  components.insert(i);
	  dfs(i);
	}
  }
  int ans = MAX_N;
  for (int i : components) {
	fill(visited.begin(), visited.end(), false);
	maxX = 0; maxY = 0; minX = MAX_N; minY = MAX_N;
    dfs(i);
	ans = min(ans, 2*(maxX - minX) + 2*(maxY - minY));
  }
  cout << ans << "\n";
}