#include <bits/stdc++.h>
using namespace std;

int N, a, b, outgoing[101], incoming[101], ans = -1;

int main() {
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		outgoing[a]++;
		incoming[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (outgoing[i] == 0 && ans != -1 ) {
			ans = -1;
			break;
		}
		if (outgoing[i] == 0) {
			ans = i;
		}
	}
	cout << ans << endl;
}
