#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;
int dp[MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = (int)1e9;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
	  for (int j : {1, 2}) {
	    dp[i+j] = min(dp[i+j], dp[i] + abs(a[i]-a[i+j]));
	  }
  }	
  cout << dp[n-1] << '\n';
}
