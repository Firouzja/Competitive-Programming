#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, a[20], b[20];
ll ans = 1;

int count_larger(int x) {
	int out = 0;
	for (int i = 0; i < N; i++) {
		if (b[i] >= x) out++;
	}
	return out;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];
	sort(a, a + N);
	for (int i = N - 1; i >= 0; i--) {
		ans *= count_larger(a[i]) - (N - 1 - i);
	}
	cout << ans << endl;
}
