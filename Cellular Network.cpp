#include <bits/stdc++.h>
using namespace std;

// this didn't actually work since test case 3 failed

const int INF = 1e9 + 1;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> v;
  for (int i = 0; i < n; i++) {
	int x;
	cin >> x;
	v.push_back({x, 0});
  }
  for (int i = 0; i < m; i++) {
	int x;
	cin >> x;
	v.push_back({x, 1});
  }
  sort(v.begin(), v.end());
  int ans = 0, left = 0, right = n + m - 1;
  int curLeftTower = INF, curLeftCity = INF, curRightTower = INF, curRightCity = INF;
  while (left <= right) {
	if (v[left].second == 1 && (curLeftTower == INF || v[left - 1].second != 1))
	  curLeftTower = v[left].first;
	if (v[left].second == 0 && (curLeftCity == INF || v[left - 1].second != 0))
	  curLeftCity = v[left].first;
	if (v[right].second == 1 && (curRightTower == INF || v[right - 1].second != 1))
	  curRightTower = v[right].first;
	if (v[right].second == 0 && (curRightCity == INF || v[right + 1].second != 0))
	  curRightCity = v[right].first;
	if (curLeftTower != INF && curLeftCity != INF)
	  ans = max(ans, abs(curLeftTower - curLeftCity));
	if (curRightTower != INF && curRightCity != INF)
	  ans = max(ans, abs(curRightTower - curRightCity));
	left++, right--;
  }
  cout << ans << "\n";
}
