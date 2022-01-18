#include <bits/stdc++.h>
using namespace std;

int N, Q, x, a, b;
int A[4][100001];
int prefix[4][100001];

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		A[x][i] = 1;
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < N; j++) {
			prefix[i][j + 1] = prefix[i][j] + A[i][j + 1];
		}
	}
	while (Q--) {
		cin >> a >> b;
		cout << prefix[1][b] - prefix[1][a - 1] << " ";
		cout << prefix[2][b] - prefix[2][a - 1] << " ";
		cout << prefix[3][b] - prefix[3][a - 1] << endl;
	}
}
