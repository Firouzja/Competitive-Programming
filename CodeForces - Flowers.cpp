#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const int MAX_N = 1e5+1;
const int MOD = 1e9+7;

ll dp[MAX_N+10];
ll psum[MAX_N+10];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int Q, k;
  cin >> Q >> k;
  dp[0] = 1;
  for (int i = 1; i <= MAX_N; i++) {
    dp[i] = dp[i-1];
    if (i >= k) dp[i] += dp[i-k];
    dp[i] %= MOD;
  }
  for (int i = 1; i <= MAX_N; i++) {
    psum[i] = psum[i-1] + dp[i]; 
    psum[i] %= MOD;
  }
  while (Q--) {
    int l, r; cin >> l >> r;
    ll ans = psum[r]-psum[l-1];
    cout << ((ans%MOD)+MOD)%MOD << "\n";
  }
  return 0;
}
