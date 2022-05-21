#include <bits/stdc++.h>
using namespace std;

const int di[] = {2, 1};
const int dj[] = {1, 2};

int main() {
  freopen("knight.in", "r", stdin);
  freopen("knight.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) 
	  for (int j = 0; j < m; j++) 
	    for (int d : {0, 1}) 
		    if (dp[i][j] && i+di[d] <= n && j+dj[d] <= m)
              dp[i+di[d]][j+dj[d]] += dp[i][j]; 
  cout << dp[n-1][m-1] << '\n';
}
