#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector<vector<int>> dp(3, vector<int>(n+1, (int)1e9));
  dp[0][0] = 0; 
  dp[1][0] = 0; 
  dp[2][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[0][i] = min({dp[0][i-1]+1, dp[1][i-1]+1, dp[2][i-1]+1});
    if (a[i] == 1 || a[i] == 3) dp[1][i] = min(dp[0][i-1], dp[2][i-1]);
    if (a[i] == 2 || a[i] == 3) dp[2][i] = min(dp[0][i-1], dp[1][i-1]);
  }
  cout << min({dp[0][n], dp[1][n], dp[2][n]}) << '\n';
}
