#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAX_N = 3000 + 1;

vector<vector<int>> adj(MAX_N);
vector<int> visited(MAX_N);
vector<int> closed(MAX_N);
vector<int> arr(MAX_N);
int nodes = 0;

void dfs(int node) {
	if (visited[node] || closed[node]) 
	  return;
	nodes++;
	visited[node] = true;
	for (int u : adj[node]) {
		if (!visited[u]) 
		  dfs(u);
	}
}

int main() {
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
    for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) cin >> arr[i];
	dfs(1);
	cout << (nodes == n ? "YES\n" : "NO\n");
	for (int i = 0; i < n - 1; i++) {
		nodes = 0;
		closed[arr[i]] = true;
		fill(visited.begin(), visited.end(), false);
		dfs(arr[n - 1]);
		cout << (nodes == n - i - 1 ? "YES\n" : "NO\n");
	}
}