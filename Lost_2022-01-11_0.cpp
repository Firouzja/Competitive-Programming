#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
	int X, Y;
	cin >> X >> Y;
	vector<int> a;
	int last = 1;
	for (int i = 0; i < 30; i++) {
		a.push_back(last + X);
		last *= -2;
	} 
	int ans = 0;
	int x = X;
	while (true) {
		while (x != a[0]) {
			ans++;
			if (x < a[0]) x++;
			if (x > a[0]) x--;
			if (x == Y) {
				cout << ans << endl;
				return 0;
			}
		}
		a.erase(a.begin());
	}
}
