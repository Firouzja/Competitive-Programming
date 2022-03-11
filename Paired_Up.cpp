#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int,int>> v;
  for (int i = 0; i < n; i++) {
	int x, y;
	cin >> x >> y;
	v.push_back(make_pair(y, x));
  }
  sort(v.begin(), v.end());
  int l = 0, r = n - 1, ans = 0;
  while (l <= r) {
	int sub = min(v[l].second, v[r].second);
	if (l == r) sub /= 2;
    ans = max(ans, v[l].first + v[r].first);
	v[l].second -= sub;
	v[r].second -= sub;
	if (v[l].second == 0) l++;
	if (v[r].second == 0) r--;
  }
  cout << ans << '\n';
}
