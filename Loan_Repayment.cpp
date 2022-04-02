#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll lastTrue(ll lo, ll hi, function<bool(ll)> ok) {
  assert(lo <= hi);
  while (lo < hi) {
	  ll mid = (hi + lo + 1) / 2;
	  if (ok(mid)) 
	    lo = mid;
	  else
	    hi = mid - 1;
  }
  return lo;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  ll n, k, m;
  cin >> n >> k >> m;
  cout << lastTrue(1, 1e12, [&](ll x) {
	  ll g = 0;
    while (k > 0 && g < n) {
      ll y = (n - g) / x;
      if (y < m) {
        ll leftover = (n-g + m-1) / m;
        return leftover <= k;
      }
      ll maxmatch = n - x*y;
      ll numdays = (maxmatch - g) / y + 1;
      if(numdays > k) 
        numdays = k;
      g += y * numdays;
      k -= numdays;
    }
    return g >= n;
  }) << '\n';
}