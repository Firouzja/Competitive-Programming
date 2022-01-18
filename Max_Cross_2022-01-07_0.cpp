#include <bits/stdc++.h>
using namespace std;

int a[100000], prefix[100000];
int N, K, B, x, ans = 100000000;

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	cin >> N >> K >> B;
	while (B--) {
		cin >> x;
		a[x]++;
	}
	for (int i = 0; i < N; i++) {
		prefix[i + 1] = prefix[i] + a[i + 1];
	}
	for (int i = 0; i <= N - K; i++) {
		ans = min(ans, prefix[i + K] - prefix[i]);
	}
	cout << ans << endl;
}
