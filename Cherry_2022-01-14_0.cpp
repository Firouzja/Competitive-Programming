#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	ll ans = 0;
	ll last = 0;
	while (n--) {
	  ll a;
      cin >> a;
	  ans = max(ans, a * last);
	  last = a;
	}
	cout << ans << endl;
  }
}

// increasing length of array can never increase minimum
// therefore the maximal product of min and max is always array of length 2
