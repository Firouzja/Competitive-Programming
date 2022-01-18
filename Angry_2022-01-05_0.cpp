#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
vector<int> v;

int get_num(int start, int direction) {
	int radius = 1;
	int prev = start;
	while (true) {
		int next = prev;
		while (next + direction >= 0 && next + direction < N 
					&& abs(v[next + direction] - v[prev]) <= radius) {
			next += direction;
		}
		if (next == prev) {
			break;
		}
		prev = next;
		radius++;
	}
	return abs(prev - start);
}

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		ans = max(ans, get_num(i, -1) + get_num(i, 1) + 1);
	}
	cout << ans << endl;
}
