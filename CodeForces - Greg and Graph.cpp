#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const ll INF = (ll)1e18;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<ll>> dp(n, vector<ll>(n, INF));
  vector<int> ord(n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
    cin >> dp[i][j];
  for (int i = 0; i < n; i++) {
    cin >> ord[i]; ord[i]--;
  }
  reverse(ord.begin(), ord.end());
  vector<int> a;
  vector<ll> ans;
  for (int i : ord) {
    ll res = 0;
    a.push_back(i);
    for (int j : a) {
      for (int k : a) {
        dp[i][k] = min(dp[i][k], dp[i][j]+dp[j][k]);
        dp[k][i] = min(dp[k][i], dp[k][j]+dp[j][i]);
      }
    }
    for (int j : a) {
      for (int k : a) {
        res += dp[j][k] = min(dp[j][k], dp[j][i]+dp[i][k]);
      }
    }
    ans.push_back(res);
  }
  for (int i = n-1; i >= 0; i--) cout << ans[i] << ' ';
  return 0;
}