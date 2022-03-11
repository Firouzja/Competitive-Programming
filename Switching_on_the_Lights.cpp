#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int n, m;
bool grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<pair<int,int>> adj[MAXN][MAXN];
int ans = 1;

void floodfill(int r, int c) {
  if (r < 0 || r >= n || c < 0 || c >= n || !grid[r][c] || vis[r][c]) return;
  vis[r][c] = true;
  floodfill(r, c + 1);
  floodfill(r, c - 1);
  floodfill(r + 1, c);
  floodfill(r - 1, c);
}

int main() {
  freopen("lightson.in", "r", stdin);
  freopen("lightson.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	a--, b--, x--, y--;
	adj[b][a].push_back(make_pair(y, x));
  }
  memset(grid, false, sizeof(grid));
  grid[0][0] = true;
  while (true) {
	memset(vis, false, sizeof(vis));
	floodfill(0, 0);
	bool done = true;
	for (int i = 0; i < n; i++) {
	  for (int j = 0; j < n; j++) {
		if (vis[i][j]) 
		  for (auto p : adj[i][j]) {
            if (!grid[p.first][p.second]) {
			  ans++;
		      grid[p.first][p.second] = true;
			  done = false;
		    }
		}
	  }
	}
	if (done) 
	  break;
  } 
  cout << ans << '\n';
}