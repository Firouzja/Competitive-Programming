#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
int n, k;
int grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
vector<pair<int,int>> component;

void floodfill(int i, int j, int color) {
  if (i < 0 || i >= n || j < 0 || j >= 10 || grid[i][j] != color || vis[i][j])
    return;
  vis[i][j] = true;
  component.push_back({i, j});
  floodfill(i, j + 1, color);
  floodfill(i, j - 1, color);
  floodfill(i + 1, j, color);
  floodfill(i - 1, j, color);
}

int main() {
  freopen("mooyomooyo.in", "r", stdin);
  freopen("mooyomooyo.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < 10; j++) {
	  char ch;
	  cin >> ch;
	  grid[i][j] = ch - '0';
	}
  }
  while (true) {
	memset(vis, false, sizeof(vis));
	bool done = true;
	for (int i = 0; i < n; i++) {
	  for (int j = 0; j < 10; j++) {
		if (grid[i][j] && !vis[i][j]) {
		  component.clear();
		  floodfill(i, j, grid[i][j]);
		  if ((int)component.size() >= k) {
			done = false;
			for (auto p : component) {
			  grid[p.first][p.second] = 0;
			}
		  }
		}
	  }
	}
	if (done) 
	  break;
	for (int j = 0; j < 10; j++) {
	  for (int i = n - 2; i >= 0; i--) {
		while (i < n - 1 && grid[i][j] && !grid[i+1][j]) {
		  grid[i+1][j] = grid[i][j];
		  grid[i][j] = 0;
		  i++;
		}
	  }
	}
  }
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < 10; j++) {
	  cout << grid[i][j];
	}
	cout << '\n';
  }
}
