#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
const int INF = (int)1e9;

struct Rectangle {
  int x1, x2, y1, y2;
};

pair<int,int> pos[MAX_N];
vector<int> adj[MAX_N];
int component[MAX_N];

void dfs(int v, int k, Rectangle &rect) {
  component[v] = k;
  rect.x1 = min(rect.x1, pos[v].first);
  rect.x2 = max(rect.x2, pos[v].first);
  rect.y1 = min(rect.y1, pos[v].second);
  rect.y2 = max(rect.y2, pos[v].second);
  for (int u : adj[v]) 
	  if (!component[u]) 
	    dfs(u, k, rect);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> pos[i].first >> pos[i].second;
  for (int i = 0; i < m; i++) {
	int u, v; cin >> u >> v; --u, --v;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
  }
  int c = 0;
  int ans = 1000000000;
  for (int i = 0; i < n; i++) {
	  if (!component[i]) {
	    Rectangle rect = {1000000000, 0, 1000000000, 0};
	    dfs(i, ++c, rect);
        ans = min(ans, 2*(rect.x2-rect.x1+rect.y2-rect.y1));
	  }
  } 
  cout << ans << '\n';
}
