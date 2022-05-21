#include <bits/stdc++.h>
using namespace std;

template <class T> void ckmax(T &a, const T &b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> arr(n);
  for (int i = 0; i < n; i++) {
	  for (int j = 0; j <= i; j++) {
	    int x; cin >> x; arr[i].push_back(x);
    }
  }
  vector<vector<int>> dp(n, vector<int>(n, -1));
  dp[0][0] = arr[0][0];
  for (int i = 1; i < n; i++) 
	  for (int j = 0; j <= i; j++) 
	    for (int k : {0, 1})
	      ckmax(dp[i][j], dp[i-1][j-k]+arr[i][j]);
  int ans = 0;
  for (int j = 0; j < n; j++)
    ckmax(ans, dp[n-1][j]);
  cout << ans << '\n';
}
