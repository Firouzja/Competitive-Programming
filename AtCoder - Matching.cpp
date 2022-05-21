#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 21;
const int MOD = (int) 1e9 + 7;

bool a[MAX_N][MAX_N];
int dp[1 << MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) 
	  for (int j = 0; j < n; j++) 
	    cin >> a[i][j];
  dp[0] = 1;
  for (int mask = 0; mask < (1 << n); mask++) {
    int sum = __builtin_popcount(mask);
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) || !a[sum][i]) continue;
      dp[mask | (1 << i)] += dp[mask];
      dp[mask | (1 << i)] %= MOD;
    }
  }
  cout << dp[(1 << n) - 1] << '\n';
}
