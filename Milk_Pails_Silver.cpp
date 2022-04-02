#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
int x, y, k, m;
bool visited[MAXN][MAXN][MAXN];
int ans;

void floodfill(int i, int j, int ops) {
  if (visited[i][j][ops] || ops > k)
    return;
  visited[i][j][ops] = true;
  ans = min(ans, abs(m - (i + j)));
  ops++;
  floodfill(x, j, ops); // fill first pail to top
  floodfill(i, y, ops); // fill second pail to top
  floodfill(0, j, ops); // empty first pail
  floodfill(i, 0, ops); // empty second pail
  if (i + j <= x)
	floodfill(i + j, 0, ops);
  else
    floodfill(x, j - (x - i), ops);
  if (i + j <= y)
    floodfill(0, i + j, ops);
  else 
    floodfill(i - (y - j), y, ops);
}

int main() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> x >> y >> k >> m;
  ans = m;
  floodfill(0, 0, 0);
  cout << ans << '\n';
}