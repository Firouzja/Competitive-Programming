#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
int min1_x, min2_x, min1_y, min2_y, max1_x, max2_x, max1_y, max2_y;

void check_min_x(int x) {
  if (x < min1_x) {
	min2_x = min1_x;
	min1_x = x;
	return;
  }
  min2_x = min(min2_x, x);
}

void check_max_x(int x) {
  if (x > max1_x) {
	max2_x = max1_x;
	max1_x = x;
	return;
  }
  max2_x = max(max2_x, x);
}

void check_min_y(int y) {
  if (y < min1_y) {
	min2_y = min1_y;
	min1_y = y;
	return;
  }
  min2_y = min(min2_y, y);
}

void check_max_y(int y) {
  if (y > max1_y) {
	max2_y = max1_y;
	max1_y = y;
	return;
  }
  max2_y = max(max2_y, y);
}

signed main() {
  freopen("reduce.in", "r", stdin);
  freopen("reduce.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  min1_x = INF, min2_x = INF, min1_y = INF, min2_y = INF;
  max1_x = 0, max2_x = 0, max1_y = 0, max2_y = 0;
  map<int,set<int>> m;
  for (int i = 0; i < n; i++) {
	int x, y;
	cin >> x >> y;
	m[x].insert(y);
	check_max_x(x);
	check_min_x(x);
	check_max_y(y);
	check_min_y(y);
  }
  int ans = INF;
  if (m[max1_x].count(min1_y)) ans = min(ans, (max2_x - min1_x) * (max1_y - min2_y));
  if (m[max1_x].count(max1_y)) ans = min(ans, (max2_x - min1_x) * (max2_y - min1_y));
  if (m[min1_x].count(min1_y)) ans = min(ans, (max1_x - min2_x) * (max1_y - min2_y));
  if (m[min1_x].count(max1_y)) ans = min(ans, (max1_x - min2_x) * (max2_y - min1_y));
  ans = min(ans, (max2_x - min1_x) * (max1_y - min1_y));
  ans = min(ans, (max1_x - min2_x) * (max1_y - min1_y));
  ans = min(ans, (max1_x - min1_x) * (max2_y - min1_y));
  ans = min(ans, (max1_x - min1_x) * (max1_y - min2_y));
  cout << ans << "\n";
}

