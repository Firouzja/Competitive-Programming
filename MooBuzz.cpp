#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
  long long ret = (x / 8) * 15;
  int mod = x % 15;
  if (mod >= 8) ret++;
  if (mod >= 7) ret++;
  if (mod >= 4) ret++;
  if (mod >= 2) ret++;
  if (mod >= 1) ret++;
  return ret;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  long long n;
  cin >> n;
  long long lo = 0, hi = 50;
  while (lo <= hi) {
	  long long mid = lo + (hi - lo) / 2;
	  if (f(mid) == n) {
      while (mid % 3 == 0 || mid % 5 == 0)
        mid--;
	    cout << mid << '\n';
	    return 0;
	  }
      else if (f(mid) > n) 
	    hi = mid - 1;
	  else
	    lo = mid + 1;
  }
}
