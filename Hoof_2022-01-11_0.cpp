#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	int a[3][100001];

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		char x;
		cin >> x;
		a[0][i] = a[0][i - 1];
		a[1][i] = a[1][i - 1];
		a[2][i] = a[2][i - 1];
		if (x == 'S') a[0][i]++; 
		if (x == 'H') a[1][i]++;
		if (x == 'P') a[2][i]++;
	}

	int ans = 0;

	for (int i = 0; i <= N; i++) {
		int hp, hs, ph, ps, sh, sp;
		hp = a[0][i] + a[1][N] - a[1][i - 1];
		hs = a[0][i] + a[2][N] - a[2][i - 1];
		ph = a[1][i] + a[0][N] - a[0][i - 1];
		ps = a[1][i] + a[2][N] - a[0][i - 1];
		sh = a[2][i] + a[0][N] - a[0][i - 1];
		sp = a[2][i] + a[1][N] - a[1][i - 1];
		ans = max(ans, max({hp, hs, ph, ps, sh, sp}));
	}

	cout << ans << endl;
}

// H - 0
// P - 1
// S - 2
