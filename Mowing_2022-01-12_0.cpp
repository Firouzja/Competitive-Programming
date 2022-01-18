#include <bits/stdc++.h>
using namespace std;

int A[2002][2002];

int main() {
  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);
  int N;
  cin >> N;
  int x = 1000, y = 1000, t = 0, ans = 1e9;
  while (N--) {
    char a; int b;
	cin >> a >> b;
    while (b--) {
	  t++;
	  if (a == 'N') y++;
      if (a == 'S') y--;
	  if (a == 'E') x++;
	  if (a == 'W') x--;
	  if (A[x][y] != 0) {
	    ans = min(ans, t - A[x][y]);
	  }
	  A[x][y] = t;
	}
  }
  cout << ans << endl;
}
