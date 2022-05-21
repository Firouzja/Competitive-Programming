#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) 
	  cin >> a[i];
  vector<int> dp(n+2, 0);
  vector<int> seen(100001, 0);
  for (int i = n; i >= 1; i--) {
	dp[i] = dp[i+1];
    if (!seen[a[i]]) dp[i]++;
	seen[a[i]]++;
  }
  vector<int> queries(m);
  for (int i = 0; i < m; i++)
    cin >> queries[i];
  for (int i = 0; i < m; i++)
    cout << dp[queries[i]] << '\n';
  return 0;
}
