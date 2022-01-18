#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	int N;
	cin >> N;
	int s[101], t[101], b[101];
	for (int i = 0; i < N; i++) {
		cin >> s[i] >> t[i] >> b[i];
	}
	int ans = 0;
	for (int time = 1; time <= 1000; time++) {
		int cur = 0;
		for (int i = 0; i < N; i++) {
			if (s[i] <= time && time <= t[i]) {
				cur += b[i];
			}
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
	return 0;
}
