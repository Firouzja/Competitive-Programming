#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9;
vector<int> v;
int n, max_a, min_a;

void solve() {
  cin >> n;
  v.resize(n);
  max_a = 0, min_a = MAX_N;
  for (int i = 0; i < n; i++) {
	cin >> v[i];
	max_a = max(max_a, v[i]);
	min_a = min(min_a, v[i]);
  }
  int ans = MAX_N;
  for (int i = 0; i < 100; i++) {
	for (int j = 0; j < 100; j++) {
	  if (i + j > 100) break;
	  bool most = false, least = false;
      for (int k = 0; k <= i - 1; k++) {
        if (v[k] == max_a) most = true;
	    if (v[k] == min_a) least = true;
      }
      for (int k = n - 1; k >= n - j; k--) {
	    if (v[k] == max_a) most = true;
	    if (v[k] == min_a) least = true;
      }
	  if (most && least) {
		ans = min(ans, i + j);
	  }
	}
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
	solve();
  }
}
