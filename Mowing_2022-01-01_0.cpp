#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int N, x = 1000, y = 1000;
int a[2002][2002];
vector<pair<char,int>> v;

int main() {
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		char a; int b;
		cin >> a >> b;
		v[i] = make_pair(a, b);
	} 
	for (int i = 0; i < 2002; i++) {
		for (int j = 0; j < 2002; j++) {
			a[i][j] = 0;
		}
	}
	int t = 0, ans = 987654;
	while (v.size() > 0) {
		t++;
		if (v[0].f == 'N') y++;
		else if (v[0].f == 'S') y--;
		else if (v[0].f == 'E') x++;
		else if (v[0].f == 'W') x--;
		if (a[x][y] != 0) ans = min(ans, t - a[x][y]);
		a[x][y] = t;
		v[0].s--;
		if (v[0].s == 0) v.erase(v.begin());
	}
	if (ans == 987654) ans = -1;
	cout << ans << endl;
	return 0;
}
