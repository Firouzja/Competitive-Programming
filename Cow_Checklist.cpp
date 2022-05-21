#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

struct Cow { 
  int x, y;
};

int dist(Cow a, Cow b) {
  int dx = a.x - b.x, dy = a.y - b.y;
  return dx*dx + dy*dy;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int h, g;
  cin >> h >> g;
  vector<Cow> a(h), b(g);
  for (int i = 0; i < h; i++)
    cin >> a[i].x >> a[i].y;
  for (int j = 0; j < g; j++)
    cin >> b[j].x >> b[j].y;
  ll dp[2][1001][1001];
  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= g; j++) {
      dp[0][i][j] = 1e18;
      dp[1][i][j] = 1e18;
    }
  }
  dp[0][1][0] = 0;
  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= g; j++) {
      if (i > 0 && j > 0) {
        dp[0][i][j] = min(dp[0][i][j], dp[1][i-1][j]+dist(a[i-1], b[j-1]));
        dp[1][i][j] = min(dp[1][i][j], dp[0][i-1][j]+dist(b[j-1], a[i-1]));
      }
      if (i > 1) dp[0][i][j] = min(dp[0][i][j], dp[0][i-1][j]+dist(a[i-1], a[i-2]));
      if (j > 1) dp[1][i][j] = min(dp[1][i][j], dp[1][i][j-1]+dist(b[j-1], b[j-2]));
    }
  }
  cout << dp[0][h][g] << '\n';
  return 0;
}