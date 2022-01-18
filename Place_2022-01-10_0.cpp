#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	int N;
	cin >> N;

	vector<int> A(N), B(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		B[i] = A[i];
	}

	sort(B.begin(), B.end());

	int count = 0;

	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) count++;
	}

	cout << count - 1 << endl;
}
