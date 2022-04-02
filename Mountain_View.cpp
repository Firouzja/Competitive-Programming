#include <bits/stdc++.h>
using namespace std;

struct Mountain {
  int l, r;
};

bool cmp(Mountain a, Mountain b) {
  if (a.l == b.l)
    return a.r > b.r;
  return a.l < b.l;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Mountain> mountains;
  for (int i = 0; i < n; i++) {
	int x, y;
	cin >> x >> y;
	mountains.push_back({x - y, x + y});
  }
  sort(mountains.begin(), mountains.end(), cmp);
  int rightMost = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
	if (mountains[i].r > rightMost) {
	  ans++;
	  rightMost = mountains[i].r;
	}
  }
  cout << ans << '\n';
}