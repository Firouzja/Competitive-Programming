#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MOD = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  iota(all(a), 1);
  int sum = accumulate(all(a), 0);
  if (sum % 2 == 1) {
    cout << "0\n";
    return 0;
  }
  sum /= 2;
  vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i][j] += dp[i-1][j];
      if (j-a[i-1] >= 0) {
        dp[i][j] += dp[i-1][j-a[i-1]];
      }
      dp[i][j] %= MOD;
    }
  }
  cout << dp[n-1][sum] << '\n';
}