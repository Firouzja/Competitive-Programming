#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  ll n;
  cin >> n;
  ll ans = 0;
  ll neg_one_count = 0;
  bool zero_exists = false;
  while (n--) {
	ll x;
	cin >> x;
	if (x == 0) {
	  zero_exists = true;
	  ans++;
	}
	else if (x < 0) {
	  neg_one_count++;
	  ans += abs(x + 1);
	}
	else {
	  ans += abs(x - 1);
	}
  }
  if (neg_one_count % 2 != 0 && !zero_exists) {
	ans += 2;
  }
  cout << ans << "\n";
}

// number of -1 must be even
