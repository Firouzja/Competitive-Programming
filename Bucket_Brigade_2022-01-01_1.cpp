#include <bits/stdc++.h>
#define y first
#define x second
using namespace std;

int main() {
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	pair<int,int> a[3];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char c;
			cin >> c;
			if (c == 'B') a[0] = make_pair(i, j);
			else if (c == 'L') a[1] = make_pair(i, j);
			else if (c == 'R') a[2] = make_pair(i, j);
		}
	}
	int ans = abs(a[0].x - a[1].x) + abs(a[0].y - a[1].y) - 1;
	if (a[0].x == a[1].x && a[1].x == a[2].x) {
		int b = a[0].y, l = a[1].y, r = a[2].y;
		if ((r < b && r > l) || (r > b && r < l)) ans += 2;
	}
	if (a[0].y == a[1].y && a[1].y == a[2].y) {
		int b = a[0].x, l = a[1].x, r = a[2].x;
		if ((r < b && r > l) || (r > b && r < l)) ans += 2;
	}
	cout << ans << endl;
	return 0;
}