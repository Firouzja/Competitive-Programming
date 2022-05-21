#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("ladder.in", "r", stdin);
  freopen("ladder.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> gain(n+1);
  for (int i = 1; i <= n; i++)
    cin >> gain[i];
  vector<int> dp(n+1, -1*1e9);
  dp[0] = 0;
  for (int i = 0; i <= n; i++) 
	  for (int j : {1, 2}) 
	    if (i+j <= n) 
		    dp[i+j] = max(dp[i+j], dp[i]+gain[i+j]);
  cout << dp[n] << '\n';
}
