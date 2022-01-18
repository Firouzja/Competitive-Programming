#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> p(N), t(N), d(N);
	for (int i = 0; i < N; i++) cin >> p[i];
	for (int i = 0; i < N; i++) { cin >> t[i]; d[i] = p[i] - t[i]; }
	int first_nonzero = 0, ans = 0;
	while (true) {
		while (first_nonzero < N && d[first_nonzero] == 0) {
			first_nonzero++;
		}
		if (first_nonzero == N) {
			break;
		}
		int r = first_nonzero;
		auto sign = [&] (int x) {
			if (x < 0) return -1;
			if (x > 0) return 1;
			return 0;
		};
		while (r + 1 < N && sign(d[r + 1]) == sign(d[first_nonzero])) {
			r++;
		}
		for (int i = first_nonzero; i <= r; i++) {
			if (d[i] < 0) d[i]++;
			else d[i]--;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}
