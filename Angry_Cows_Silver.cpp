#include <bits/stdc++.h>
using namespace std;

int firstTrue(int lo, int hi, function<bool(int)> f) {
  hi++;
  while (lo < hi) {
	int mid = lo + (hi - lo) / 2;
	if (f(mid))
	  hi = mid;
	else
	  lo = mid + 1;
  }
  return hi;
}

int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k, x;
  cin >> n >> k;
  multiset<int> bales;
  while (n--) {
	cin >> x;
	bales.insert(x);
  }
  cout << firstTrue(1, *bales.end(), [&] (int r) {
	int curPos = *bales.upper_bound(0) + r;
	int ct = 1;
	while (true) {
	  auto it = bales.upper_bound(curPos + r);
	  if (it == bales.end()) break;
      curPos = *it + r;
	  ct++;
	}
	return ct <= k;
  }) << "\n";
}
