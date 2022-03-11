#include <bits/stdc++.h>
#define start first
#define time second
using namespace std;

const int MAX_N = 1e6;

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
  for (int t = 0; t < MAX_N + 1; t++) {
	if (v.size() == 0) {
	  cout << t << '\n';
	  return 0;
	}
	if (t >= v[0].start) {
	  v[0].time--;
	  if (v[0].time == 0) {
		v.erase(v.begin());
	  }
	}
  }
}
