#include <bits/stdc++.h>
using namespace std;

int firstTrue(int lo, int hi, function<bool(int)> f) {
  int ret = 0;
  hi++;
  while (lo < hi) {
	int mid = lo + (hi - lo) / 2;
	if (f(mid)) {
	  hi = mid - 1;
	  ret = mid;
	}
	else
	  lo = mid + 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int maxSum = 0;
  for (int& i : a) { 
    cin >> i;
	maxSum += i;
  }
  cout << firstTrue(0, maxSum, [&] (int x) {
    int sum = 0, ct = 0;
    for (int i : a) {
	  if (i > x)
	    return false;
	  if (sum + i > x) {
	    sum = 0;
		ct++;
	  }
	  sum += i;
	}
	if (sum > 0) 
	  ct++;
	return ct <= k;
  }) << "\n";   
}
