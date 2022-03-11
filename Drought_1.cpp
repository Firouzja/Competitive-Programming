#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n;
  cin >> n;
  if (n == 1) return 0;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  int ans = 0;
  int j = 2;
  while (j--) {
	for (int i = 1; i < n - 1; i++) {
	  if (v[i] > v[i - 1]) {
		int dif = v[i] - v[i - 1];
		ans += 2 * dif;
		v[i + 1] -= dif;
		v[i] = v[i - 1];
	  }
	}
	if (v[n - 1] > v[n - 2]) return -1;
	reverse(v.begin(), v.end());
  }
  if (v[0] < 0) return -1;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
	cout << solve() << "\n";
  }
}
