#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int totalPetals = 0;
			for (int k = i; k <= j; k++) totalPetals += v[k];
			bool good = false;
			for (int k = i; k <= j; k++) {
				if (v[k] * (j - i + 1) == totalPetals) good = true;
			}
			if (good) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
