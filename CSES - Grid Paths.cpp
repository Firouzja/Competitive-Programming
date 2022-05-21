#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1010;
const int MOD = 1e9+7;

int grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    char ch; cin >> ch; grid[i][j] = ch == '.';
  }
  if (!grid[0][0]) {
    cout << "0\n";
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    if (!grid[i][j]) continue;
    if (i != 0) (dp[i][j] += dp[i-1][j]) %= MOD;
    if (j != 0) (dp[i][j] += dp[i][j-1]) %= MOD;
  }
  cout << dp[n-1][n-1] << "\n";
  return 0;
}
