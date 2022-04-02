#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  set<int> cows; multiset<int> gaps;
  cows.insert(0); cows.insert(1e8); gaps.insert(-1e8);
  for (int i = 0; i < n; i++) {
	  int x; cin >> x; x /= 12; ++x;
	  if (!cows.count(x)) {
	    auto it1 = cows.upper_bound(x), it2 = it1; --it2;
	    gaps.erase(gaps.find(-1 * (*it1-*it2)));
	    gaps.insert(-1 * (*it1-x));
	    gaps.insert(-1 * (x-*it2));
	    cows.insert(x);
	  }
  }
  int ans = 1;
  for (int i : gaps) {
    if (k > 1) k--;
    else ans += -1 * i + 1;
  }
  cout << ans * 12 << '\n';
}