#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int n, k;
vector<int> a;
ll maxSum = 0;

ll firstTrue(ll lo, ll hi, function<bool(ll)> f) {
  hi++;
  while (lo < hi) {
	  ll mid = lo+(hi-lo)/2;
	  f(mid) ? hi = mid : lo = mid+1;
  }
  return lo;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxSum += a[i];
  }
  cout << firstTrue(0, maxSum, [] (ll s) {
    int sum = 0, ct = 1;
    for (auto i : a) {
      if (sum + i > s) {
        ct++;
        sum = 0;
      }
      sum += i;
    }
    return (ct <= k);
  }) << '\n';
}
