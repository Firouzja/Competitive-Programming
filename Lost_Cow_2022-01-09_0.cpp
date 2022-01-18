#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

	int X, Y;
	cin >> X >> Y;

	vector<int> a(20); 
	int last = 1;
	for (int i = 0; i < 20; i++) {
		a[i] = X + last;
		last *= -2;
	}
	
	int x = X, ans = 0;
	while (true) {
		while (x != a[0]) {
			ans++;
			if (x < a[0]) x++;
			else x--;
			if (x == Y) {
				cout << ans << endl;
				return 0;
			}
		}
		a.erase(a.begin());
	}
}
