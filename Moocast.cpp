#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200;
int n, nodes = 0;
vector<array<int,3>> arr;
vector<int> adj[MAX_N];
vector<bool> visited(MAX_N);

void dfs(int node) {
  visited[node] = true;
  nodes++;
  for (int u : adj[node]) {
	if (!visited[u])
	  dfs(u);
  }
}

int main() {
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  arr.resize(n);
  for (auto& i : arr)
    cin >> i[0] >> i[1] >> i[2];
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  if ((int)sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) 
	        + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1])) < arr[i][2])
	    adj[i].push_back(j);
	}
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
	fill(visited.begin(), visited.end(), false);
	nodes = 0;
	dfs(i);
    ans = max(ans, nodes);
  }
  cout << ans << "\n";
}
