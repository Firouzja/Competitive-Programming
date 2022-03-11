#include <bits/stdc++.h>
using namespace std;

int solve(int k) {
  int x;
  cin >> x;
  int ltravel = 0, rtravel = 0, ret = 0;
  for (int t = 1;; t++) {
	ltravel += t;
	ret++;
	if (ltravel + rtravel >= k) return ret;
    if (t >= x) {
	  rtravel += t;
	  ret++;
	  if (ltravel + rtravel >= k) return ret;
	}
  }
}

int main() {
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k, n;
	cin >> k >> n;
	while (n--) {
	  cout << solve(k) << '\n';
	}
}
