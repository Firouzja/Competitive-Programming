#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, A[20], B[20];

int count(int x) {
	int out = 0;
	for (int i = 0; i < N; i++) {
		if (B[i] >= x) out++;
	}
	return out;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	sort (A, A + N);
	ll ans = 1;
	for (int i = N - 1; i >= 0; i--) {
		ans *= count(A[i]) - (N-1 - i);
	}
	cout << ans << endl;
}
