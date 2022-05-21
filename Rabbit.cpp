#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("lepus.in", "r", stdin);
  freopen("lepus.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
	  char ch; cin >> ch;
	  if (ch == '"') arr[i] = 1;
	  if (ch == '.') arr[i] = 0;
	  if (ch == 'w') arr[i] = -1;
  }
  vector<int> dp(n, -1);
  dp[0] = 0;
  for (int i = 1; i < n; i++) 
      if (arr[i] != -1)
	      for (int j : {1, 3, 5}) 
	        if (dp[i-j] != -1 && i >= j) 
		        dp[i] = max(dp[i], dp[i-j]+arr[i]);
  cout << dp[n-1] << '\n';
}
