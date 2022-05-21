#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

void solve() {
  int n;
  cin >> n;
  vector<int> dp(n+1, 0);
  for (int i = 1; i <= n; i++) {
	char ch; cin >> ch;
    dp[i] = ch - '0';
  }
  for (int i = 1; i <= n; i++)
    dp[i] += dp[i-1];
  map<int,ll> sumDist;
  for (int i = 0; i <= n; i++)
    sumDist[dp[i]-i]++;
  ll ans = 0;
  for (pair<ll,ll> p : sumDist) {
    ll c = p.second;
    ans += c*(c-1)/2;
  } 
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
	  solve();
  }
}
