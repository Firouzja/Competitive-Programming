#include <bits/stdc++.h>
using namespace std;

bool a[10][10];

int update(int i, int j) {
  if (a[i][j]) {
	for (int ii = 0; ii <= i; ii++) {
	  for (int jj = 0; jj <= j; jj++) {
		a[ii][jj] = !a[ii][jj];
	  }
	}
	return 1;
  }
  return 0;
}

int main() {
  freopen("cowtip.in", "r", stdin);
  freopen("cowtip.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
	cin >> s;
	for (int j = 0; j < n; j++) {
	  a[i][j] = (s[j] == '0' ? false : true);
	}
  }
  int x = n - 1, y = n - 1, ans = 0;
  while (x >= 0 && y >= 0) {
	ans += update(x, y);
	if (x != y) {
	  ans += update(y, x);
	}
	if (x != 0) {
	  x--;
	}
    else {
	  y--;
	  x = y;
	}
  }
  cout << ans << "\n";
}
