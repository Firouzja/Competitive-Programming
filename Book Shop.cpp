#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> price(n), page(n);
  for (int i = 0; i < n; i++) cin >> price[i];
  for (int i = 0; i < n; i++) cin >> page[i];
  vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = dp[i-1][j];
      if (j-price[i-1] >= 0)
        dp[i][j] = max(dp[i][j], dp[i-1][j-price[i-1]]+page[i-1]);
    }
  }
  cout << dp[n][x] << '\n';
}
