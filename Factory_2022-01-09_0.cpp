#include <bits/stdc++.h>
using namespace std;

int A[101];
int N, a, b;

int main() {
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		A[a]++;
	}
	int ans = -1;
	for (int i = 1; i <= N; i++) {
		if (A[i] == 0 && ans == -1) {
			ans = i;
		}
		else if (A[i] == 0 && ans != -1) {
			ans = -1;
			break;
		}
	}
	cout << ans << endl;
}
