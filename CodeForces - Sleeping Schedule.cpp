#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<vector<int>> dp(h+1, vector<int>(n+1, -1));
  vector<int> a(n+1);
  for (int i = 0; i < n; i++) cin >> a[i];
  dp[0][0] = 0;
  for (int j = 0; j < n; j++) {
    int k = a[j];
    for (int i = 0; i < h; i++) {
      if (dp[i][j] == -1) continue;
      bool good1 = ((i+k)%h >= l && (i+k)%h <= r);
      bool good2 = ((i+k-1)%h >= l && (i+k-1)%h <= r);
      dp[(i+k)%h][j+1] = max(dp[(i+k)%h][j+1], dp[i][j]+good1);
      dp[(i+k-1)%h][j+1] = max(dp[(i+k-1)%h][j+1], dp[i][j]+good2);
    }
  }
  int ans = -1;
  for (int i = 0; i < h; i++) {
    ans = max(ans, dp[i][n]);
  }
  cout << ans << "\n";
  return 0;
}
