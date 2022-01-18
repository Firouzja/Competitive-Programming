#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	int N, M;
	cin >> N >> M;
	int n[100], m[100];
	for (int i = 0; i < 100; i++) {
		n[i] = 0;
		m[i] = 0;
	}
	while (N--) {
		int a, b;
		cin >> a >> b;
		n[a-1] = b;
	}
	while (M--) {
		int a, b;
		cin >> a >> b;
		m[a-1] = b;
	}
	int cur_n, cur_m;
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		if (n[i] != 0) cur_n = n[i];
		if (m[i] != 0) cur_m = m[i];
		ans = max(ans, cur_m - cur_n);	
	}
	cout << ans << endl;
}