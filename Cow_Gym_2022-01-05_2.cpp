#include <bits/stdc++.h>
using namespace std;

bool b[20][20];
int K, N, ans = 0;

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			b[i][j] = false;
		}
	}
	cin >> K >> N;
	while (K--) {
		int a[20];
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				b[a[i]-1][a[j]-1] = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!b[i][j] || !b[j][i]) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
