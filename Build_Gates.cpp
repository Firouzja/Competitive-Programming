#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4005;
int n, maxX = 2001, maxY = 2001, minX = 2001, minY = 2001;
bool grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

void floodfill(int x, int y) {
  if (x < minX || x > maxX || y < minY || y > maxY || grid[x][y] || visited[x][y])
    return;
  visited[x][y] = true;
  floodfill(x, y + 1);
  floodfill(x, y - 1);
  floodfill(x + 1, y);
  floodfill(x - 1, y);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  int x = 2001, y = 2001;
  map<char,pair<int,int>> dir {
	{'N', {1, 0}}, {'S', {-1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}
  };
  for (int i = 0; i < n; i++) {
	char ch;
	cin >> ch;
	grid[x + dir[ch].first][y + dir[ch].second] = true;
	grid[x + 2*dir[ch].first][y + 2*dir[ch].second] = true;
	x += 2*dir[ch].first;
	x += 2*dir[ch].second;
	minX = min(minX, x);
	minY = min(minY, y);
	maxX = max(maxX, x);
	maxY = max(maxY, y);
  }
  minX--, maxX++, minY--, maxY++;
  int ans = 0;
  for (int i = minY; i <= maxY; i++) {
	for (int j = minX; j <= maxX; j++) {
	  if (!visited[j][i] && !grid[j][i]) {
		ans++;
		floodfill(j, i);
	  }
	}
  }
  cout << ans - 1 << '\n';
}