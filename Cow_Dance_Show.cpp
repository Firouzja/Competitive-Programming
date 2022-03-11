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
  freopen("cowdance.in", "r", stdin);
  freopen("cowdance.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (auto& i : a) 
    cin >> i;
  cout << firstTrue(0, n, [&] (int x) {
	multiset<int> curStopTimes;
	for (int i = 0; i < x; i++) 
	  curStopTimes.insert(a[i]);
	for (int i = x; i < n; i++) {
	  auto it = curStopTimes.upper_bound(0);
      curStopTimes.erase(it);
	  curStopTimes.insert(*it + a[i]);
	}
	auto endTime = curStopTimes.end(); --endTime;
	return *endTime <= t;
  }) << "\n";
}
