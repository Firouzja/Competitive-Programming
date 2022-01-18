#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
	cin >> v[i];
  }
  sort(v.begin(), v.end());
  cout << v.back() - v[0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
	solve();
  }
}
