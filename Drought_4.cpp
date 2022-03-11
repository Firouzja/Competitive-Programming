#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v) 
    cin >> i;
  int ret = 0;
  for (int j = 0; j < 2; j++) {
	for (int i = 1; i < n - 1; i++) {
	  if (v[i] > v[i - 1]) {
		int sub = v[i] - v[i - 1];
		ret += 2 * sub;
		v[i + 1] -= sub;
		v[i] = v[i - 1];
	  }
	}
	if (v[n - 1] > v[n - 2]) return -1;
	reverse(v.begin(), v.end());
  }
  if (v[0] < 0) return -1;
  return ret;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
	cout << solve() << "\n";
  }
}
