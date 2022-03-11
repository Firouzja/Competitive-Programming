#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n, curArea = 0, curPerimeter = 0, area = 0, perimeter = 0;
char g[MAXN][MAXN];
bool visited[MAXN][MAXN];

void floodfill(int r, int c) {
  if (r < 0 || r >= n || c < 0 || c >= n) {
	curPerimeter++;
	return;
  }
  if (visited[r][c])
    return;
  if (g[r][c] == '.') {
	curPerimeter++;
	return;
  }
  visited[r][c] = true;
  if (g[r][c] == '#')
    curArea++;
  floodfill(r, c + 1);
  floodfill(r, c - 1);
  floodfill(r + 1, c);
  floodfill(r - 1, c);
}

int main() {
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  cin >> g[i][j];
	}
  }
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  if (g[i][j] == '#' && !visited[i][j]) {
		floodfill(i, j);
		if (area == curArea)
		  perimeter = min(perimeter, curPerimeter);
		else if (curArea > area) {
		  area = curArea;
		  perimeter = curPerimeter;
		}
		curArea = 0, curPerimeter = 0;
	  }
	}
  }
  cout << area << ' ' << perimeter << '\n';
}
