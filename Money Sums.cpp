#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) 
    cin >> a[i];
  vector<vector<bool>> dp(n+1, vector<bool>(n*1000+1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n*1000; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-a[i-1];
      if (left >= 0 && dp[i-1][left]) {
        dp[i][j] = true;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n*1000; i++) 
    if (dp[n][i])
      ans.push_back(i);
  cout << ans.size() << '\n';
  for (int i : ans) cout << i << ' ';
  cout << '\n';
}
