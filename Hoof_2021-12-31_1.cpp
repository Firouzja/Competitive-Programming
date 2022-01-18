#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

vector<pair<int,int>> v;

int wins(int x, int y, int z) {
	int out = 0;
	for (auto i : v) {
		if (i.f == x && i.s == y) out++;
		if (i.f == y && i.s == z) out++;
		if (i.f == z && i.s == x) out++;
	}
	return out;
}

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = make_pair(a, b);
	}
	int ans = 0;
	ans = max(ans, wins(1, 2, 3));
	ans = max(ans, wins(1, 3, 2));
	ans = max(ans, wins(2, 1, 3));
	ans = max(ans, wins(2, 3, 1));
	ans = max(ans, wins(3, 1, 2));
	ans = max(ans, wins(3, 2, 1));
	cout << ans << endl;
	return 0;
}
