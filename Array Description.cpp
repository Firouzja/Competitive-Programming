#include <iostream>
#include <vector>
using namespace std;

const int MOD = (int)1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
  if (a[0] == 0) 
    fill(dp[0].begin(), dp[0].end(), 1);
  else 
    dp[0][a[0]] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == 0) {
      for (int j = 1; j <= m; j++) {
	      for (int k : {j-1,j,j+1}) {
	        if (k >= 1 && k <= m) {
	          (dp[i][j] += dp[i-1][k]) %= MOD;
	        }
	      }
      }
    } 
    else {
      for (int k : {a[i]-1, a[i], a[i]+1}) {
	      if (k >= 1 && k <= m) {
	        (dp[i][a[i]] += dp[i-1][k]) %= MOD;
	      }
      }
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; j++) 
    (ans += dp[n-1][j]) %= MOD;
  cout << ans << endl;
}