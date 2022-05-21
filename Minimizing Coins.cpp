#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  vector<int> dp(x+1, 1e9);
  dp[0] = 0;
  for (int i = 0; i <= x; i++) {
    for (int j : coins) {
      if (i + j <= x) {
        dp[i+j] = min(dp[i+j], dp[i]+1);
      }
    }
  }
  cout << (dp[x] == 1e9 ? -1 : dp[x]) << '\n';
}
