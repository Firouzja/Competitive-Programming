#include <bits/stdc++.h>
using namespace std;

int a[3];

int min_moves() {
	if (a[2] - a[1] == 1 && a[1] - a[0] == 1) return 0;
	if (a[2] - a[1] == 2 || a[1] - a[0] == 2) return 1;
	return 2;
}

int max_moves() {
	if (a[2] - a[1] == 1 && a[1] - a[0] == 1) return 0;
	return max(a[2] - a[1], a[1] - a[0]) - 1;
}

int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << min_moves() << endl << max_moves() << endl;
}


// if already sorted min is 0, max is 0
// if there exists difference of 2, min is 1
// otherwise min is always 2
// max is largest gap minus 1