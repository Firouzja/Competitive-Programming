#include <bits/stdc++.h>
using namespace std;

int dp[3][100001][21];
int a[100001];

int main() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    char ch; cin >> ch; 
    if (ch == 'H') a[i] = 0;
    if (ch == 'P') a[i] = 1;
    if (ch == 'S') a[i] = 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 0; l < 3; l++) {
        if (l == a[i]) dp[l][i][j]++;
        dp[0][i+1][j+1] = max(dp[0][i+1][j+1], dp[k][i][j]);
        dp[1][i+1][j+1] = max(dp[1][i+1][j+1], dp[k][i][j]);
        dp[2][i+1][j+1] = max(dp[2][i+1][j+1], dp[k][i][j]);
        dp[k][i+1][j] = max(dp[k][i+1][j], dp[k][i][j]);
      }
    }
  }
  cout << max({dp[0][n-1][k], dp[1][n-1][k], dp[2][n-1][k]}) << '\n';
}
