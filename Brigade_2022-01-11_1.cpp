#include <bits/stdc++.h>
#define y first
#define x second
using namespace std;

pair<int,int> B, L, R;
char c;

int main() {
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> c;
			if (c == 'B') B = make_pair(i, j);
			if (c == 'L') L = make_pair(i, j);
			if (c == 'R') R = make_pair(i, j);
		}
	}
	int ans = abs(B.y - L.y) + abs(B.x - L.x) - 1; 
	if (B.x == L.x && L.x == R.x &&
					((R.y > B.y && R.y < L.y) ||
					(R.y < B.y && R.y > L.y))) {
		ans += 2;
	}
	if (B.y == L.y && L.y == R.y &&
					((R.x > B.x && R.x < L.x) ||
					(R.x < B.x && R.x > L.x))) {
		ans += 2;
	}
	cout << ans << endl;
}

