#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, x, y;

const ll MAX_N = 1e7+1;
const ll INF = (ll)1e18;

vector<ll> dp(MAX_N, INF);

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> x >> y;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      dp[i] = min(dp[i-1]+x, dp[i/2]+y);
    } else {
      dp[i] = min(dp[i-1]+x, dp[(i+1)/2]+x+y);
    }
  }
  cout << dp[n] << "\n";
  return 0;
}
