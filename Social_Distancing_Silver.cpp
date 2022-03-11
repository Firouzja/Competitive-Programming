#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
const int INF = 2e9;
vector<pair<ll,ll>> intervals;
 
bool check(ll d) {
  ll prev = (ll)-1 * INF * INF;
  int cnt = 0;
  for (auto& i : intervals) {
    while (max(prev + d, i.first) <= i.second) {
      prev = max(prev + d, i.first);
      cnt++;
      if (cnt >= n) break;
    }
    if (cnt >= n) break;
  }
  return (cnt >= n);
}
 
int main() {
  freopen("socdist.in", "r", stdin);
  freopen("socdist.out", "w", stdout);
  cin >> n >> m;
  intervals.resize(m);
  for (int i = 0; i < m; ++i) 
    cin >> intervals[i].first >> intervals[i].second;
  sort(intervals.begin(), intervals.end());
  ll lo = 1, hi = (ll)1 * INF * INF, res = -1;
  while (lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if (check(mid)) {
	  res = mid;
      lo = mid + 1;
    }
    else 
      hi = mid - 1;
  }
  cout << res << "\n";
}