#include <bits/stdc++.h>
using namespace std;

int N, B;
int x[100], y[100];

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	int ans = 100000000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int lx = x[i] + 1;
			int ly = y[j] + 1;
			int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
			for (int k = 0; k < N; k++) {
				if (x[k] > lx && y[k] > ly) q1++;
				if (x[k] < lx && y[k] > ly) q2++;
				if (x[k] < lx && y[k] < ly) q3++;
				if (x[k] > lx && y[k] < ly) q4++;
			}
			ans = min(ans, max({q1, q2, q3, q4}));
		}
	}
	cout << ans << endl;
}
