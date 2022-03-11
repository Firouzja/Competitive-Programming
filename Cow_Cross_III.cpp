#include <bits/stdc++.h>
#define start first
#define time second
using namespace std;

const int MAX_N = 1e8;

int main() {
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> v;
  for (int i = 0; i < n; i++) {
	int a, b;
	cin >> a >> b;
	v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  int cur = 0, ans = 0;
  for (int t = 0; t < MAX_N; t++) {
	if (t >= v[cur].start) {
	  t += v[cur].time;
	  cur++;
	  if (cur == n) {
		ans = t - 1;
		break;
	  }
	}
  }
  cout << ans << '\n';
}
