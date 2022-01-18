#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, ans = 0;
ll a[3][100001];
char c;

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> c;
		if (c == 'S') {
			a[0][i] = a[0][i - 1] + 1;
			a[1][i] = a[1][i - 1];
			a[2][i] = a[2][i - 1];
		}
		if (c == 'H') {
			a[1][i] = a[1][i - 1] + 1;
			a[0][i] = a[0][i - 1];
			a[2][i] = a[2][i - 1];
		}
		if (c == 'P') {
			a[2][i] = a[2][i - 1] + 1;
			a[0][i] = a[0][i - 1];
			a[1][i] = a[1][i - 1];
		}
	}
	for (ll i = 0; i <= N; i++) {
		ll hp, hs, ph, ps, sh, sp;
		hp = a[0][i] + a[1][N] - a[1][i - 1];
		hs = a[0][i] + a[2][N] - a[2][i - 1];
		ph = a[1][i] + a[0][N] - a[0][i - 1];
		ps = a[1][i] + a[2][N] - a[2][i - 1];
		sh = a[2][i] + a[0][N] - a[0][i - 1];
		sp = a[2][i] + a[1][N] - a[1][i - 1];
		ans = max(ans, max({hp, hs, ph, ps, sh, sp}));
	}
	cout << ans << endl;
}
