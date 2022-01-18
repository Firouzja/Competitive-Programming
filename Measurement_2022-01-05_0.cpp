#include <bits/stdc++.h>
using namespace std;

int cur[3][101], ch[3][101];
int N, ans = 0;

bool is_highest(int c, int d) {
	return cur[c][d] == max({cur[0][d], cur[1][d], cur[2][d]});
}

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	for (int c = 0; c < 3; c++) {
		for (int d = 0; d <= 100; d++) {
			cur[c][d] = 0;
			ch[c][d] = 0;
		}
	} 
	cin >> N;
	while (N--) {
		int c, d, m;
		string name;
		cin >> d >> name >> m;
		if (name == "Bessie") c = 0;
		if (name == "Elsie") c = 1;
		if (name == "Mildred") c = 2;
		ch[c][d] = m;
	}
	for (int c = 0; c < 3; c++) {
		for (int d = 1; d <= 100; d++) {
			cur[c][d] = cur[c][d - 1] + ch[c][d];
		}
	}
	for (int d = 1; d <= 100; d++) {
		if (is_highest(0, d) != is_highest(0, d - 1) 
				|| is_highest(1, d) != is_highest(1, d - 1) 
				|| is_highest(2, d) != is_highest(2, d - 1)) {
			ans++;
		}
	}
	cout << ans << endl;
}
