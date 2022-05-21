#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int MAX_N = 1e6;
const int MOD = (int)1e9 + 7;
ll dp[MAX_N+1];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  dp[0] = 1;
  for (int sum = 0; sum <= x; sum++) {
    for (int coin : coins) {
      if (sum - coin >= 0) {
        dp[sum] += dp[sum-coin];
        dp[sum] %= MOD;
      }
    }
  }
  cout << dp[x] << '\n';
}
