#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int MAX_N = 1e6 + 1;
const int MOD = 1e9 + 7;
ll dp[MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
	  for (int j = 1; j <= 6; j++) {
	    if (i - j >= 0) {
		    dp[i] += dp[i-j];
	    }
	  }
	  dp[i] %= MOD;
  }
  cout << dp[n] << '\n';
}
