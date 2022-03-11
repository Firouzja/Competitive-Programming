#include <bits/stdc++.h>
using namespace std;

int n;
const int INF = 1e9;

int cost(vector<int> v, int f) {
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
	if (v[i] > f) {
	  int sub = min(v[i], v[i + 1]) - f;
	  v[i] -= sub;
	  v[i + 1] -= sub;
	  sum += sub * 2;
	}
  }
  for (int i = 0; i < n - 1; i++) {
	if (v[i] != v[i + 1]) {
	  return INF;
	}
  }
  return sum;
}

void solve() {
  cin >> n;
  vector<int> v(n);
  int mn = INF, ans = INF;
  for (int i = 0; i < n; i++) {
	cin >> v[i];
	mn = min(mn, v[i]);
  }
  for (int i = 0; i <= mn; i++) {
	ans = min(ans, cost(v, i));
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
	solve();
  }
}
