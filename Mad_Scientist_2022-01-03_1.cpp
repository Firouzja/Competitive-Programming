#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
	int N;
	string A, B;
	cin >> N >> A >> B;
	bool b = false;
	int ans = 0; 
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i] && !b) {
			ans++;
			b = true;
		}
		else if (A[i] == B[i] && b) {
			b = false;
		}
	}
	cout << ans << endl;
	return 0;
}
