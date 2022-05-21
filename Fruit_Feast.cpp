#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e6;
bool dp[2][MAX_N+1];

int main() {
  freopen("feast.in", "r", stdin);
  freopen("feast.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t, a, b;
  cin >> t >> a >> b;
  dp[0][0] = true;
  for (int i = 0; i <= t; i++) {
    if (i-a >= 0) dp[0][i] |= dp[0][i-a];
    if (i-b >= 0) dp[0][i] |= dp[0][i-b];
    dp[1][i/2] |= dp[0][i];
  }
  for (int i = 0; i <= t; i++) {
    if (i-a >= 0) dp[1][i] |= dp[1][i-a];
    if (i-b >= 0) dp[1][i] |= dp[1][i-b];
  }
  for (int i = t; i >= 0; i--) if (dp[1][i]) {
    cout << i << '\n';
    return 0;
  }
}
