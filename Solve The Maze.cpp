#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60;
int n, m;
char g[MAXN][MAXN];
bool visited[MAXN][MAXN];
int rowMove[] = {0, 1, 0, -1};
int colMove[] = {1, 0, -1, 0};

void floodfill(int r, int c) {
  if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || g[r][c] == '#')
    return;
  visited[r][c] = true;
  floodfill(r, c + 1);
  floodfill(r, c - 1);
  floodfill(r + 1, c);
  floodfill(r - 1, c);
}

bool solve() {
  memset(g, '.', sizeof(g));
  memset(visited, false, sizeof(visited));
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  cin >> g[i][j];
	}
  }
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  if (g[i][j] == 'B') {
		for (int x = 0; x < 4; x++) {
		  int newRow = i + rowMove[x];
		  int newCol = j + colMove[x];
		  if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
			if (g[newRow][newCol] == 'G')
			  return false;
			if (g[newRow][newCol] == '.')
			  g[newRow][newCol] = '#';
		  }
		}
	  }
	}
  }
  floodfill(n - 1, m - 1);
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  if (g[i][j] == 'G' && !visited[i][j]) {
		return false;
	  }
	}
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) 
	cout << (solve() ? "YES" : "NO") << '\n';
}