#include <bits/stdc++.h>
using namespace std;

int K, N;
bool a[20][20];

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			a[i][j] = false;
		}
	}
	cin >> K >> N;
	while (K--) {
		int b[20];
		for (int i = 0; i < N; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				a[b[i]-1][b[j]-1] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!a[i][j] || !a[j][i]) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
