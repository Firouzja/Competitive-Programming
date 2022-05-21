#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1010;

int grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int n, m;
int ans = 0;

void floodfill(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || !grid[i][j] || vis[i][j]) return;
  vis[i][j] = true;
  floodfill(i, j+1);
  floodfill(i, j-1);
  floodfill(i+1, j);
  floodfill(i-1, j);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch; cin >> ch;
      grid[i][j] = ch == '.';
    }
  }
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j] && !vis[i][j]) {
    floodfill(i, j);
    ++ans;
  }
  cout << ans << "\n";
  return 0;
}
