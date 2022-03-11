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
  return lo;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  vector<int> times(n);
  for (auto& i : times)
    cin >> i;
  sort(times.begin(), times.end());
  cout << firstTrue(0, 2e9, [&] (int x) {
	int productsMade = 0;
	for (int time : times) {
	  productsMade += x / time;
	}
	return productsMade >= t; 
  }) << "\n";
}
