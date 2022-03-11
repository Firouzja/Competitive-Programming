#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;
int n, k, a, b, sa, sb;
vector<int> adj[MAX_N];
bool visited[MAX_N];
set<int> ans;
int original;

void dfs(int node) {
  visited[node] = true;
  if (node == original) {
	ans.insert(node);
	return;
  }
  for (int u : adj[node]) {
	if (!visited[u]) 
	  dfs(u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  while (k--) {
	cin >> a >> b >> sa >> sb;
	if (sa > sb)
	  adj[b - 1].push_back(a - 1);
	if (sb > sa)
	  adj[a - 1].push_back(b - 1);
  }
  for (int i = 0; i < n; i++) {
	original = i;
	fill(begin(visited), end(visited), false);
    for (int u : adj[i])
	  dfs(u);
  }
  cout << ans.size() << "\n";
}
