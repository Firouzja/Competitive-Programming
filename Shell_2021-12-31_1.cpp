#include <bits/stdc++.h>
using namespace std;

int a[100][3], N;

int test(int a[100][3], int x) {
	int out = 0;
	map<int,int> m;
	m[0] = 0;
	m[1] = 0;
	m[2] = 0;
	m[x]++;
	for (int i = 0; i < N; i++) {
		swap(m[a[i][0]], m[a[i][1]]);
		if (m[a[i][2]] == 1) out++;
	}
	return out;
}

int main() {
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= 3; i++) {
		ans = max(ans, test(a, i));
	} 
	cout << ans << endl;
	return 0;
}
