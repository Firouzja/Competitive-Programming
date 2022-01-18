#include <bits/stdc++.h>
using namespace std;

map<int,int> m;
int N, ans = 0;

int main() {
	freopen("crossroad.in", "r", stdin);
	freopen("crossroad.out", "w", stdout);
	for (int i = 1; i <= 10; i++) {
		m[i] = -1;
	}
	cin >> N;
	while (N--) {
		int x, y;
		cin >> x >> y;
		if (m[x] != y && m[x] != -1) {
			ans++;
		}
		m[x] = y;
	}
	cout << ans << endl;
}
