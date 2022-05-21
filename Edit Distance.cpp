#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, (int)1e9));
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++) 
    for (int j = 0; j <= m; j++) {
      if (i != 0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
      if (j != 0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
      if (i != 0 && j != 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(a[i-1]!=b[j-1]));
    }
  cout << dp[n][m] << '\n';
}
