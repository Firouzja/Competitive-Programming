#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int ans = 1e9;
	for (int i = 0; i < N; i++) {
		int cur = 0;
		for (int j = i; j < N + i; j++) {
			if (j < N) cur += v[j] * (j - i); 
			else cur += v[j - N] * (j - i);
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
}
