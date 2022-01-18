#include <bits/stdc++.h>
using namespace std;

int a[2002][2002];
int N, y = 1000, x = 1000, t = 0, ans = 1e9, d;
char c;

int main() {
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	for (int i = 0; i < 2002; i++) {
		for (int j = 0; j < 2002; j++) {
			a[i][j] = 0;
		}
	}
	cin >> N;
	while (N--) {
		cin >> c >> d;
		while (d--) {
			t++;
			if (c == 'N') y++;
			if (c == 'S') y--;
			if (c == 'E') x++;
			if (c == 'W') x--;
			if (a[y][x] != 0) ans = min(ans, t - a[y][x]);
			a[y][x] = t;
		}	
	}
	if (ans == 1e9) ans = -1;
	cout << ans << endl;
}
