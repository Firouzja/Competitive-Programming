#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);
	int N, K;
	cin >> N >> K;
	vector<string> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	int cur = v[0].size();
	cout << v[0];
	for (int i = 1; i < N; i++) {
		if (cur + v[i].size() <= K) {
			cout << " " << v[i];
			cur += v[i].size();
		}
		else {
			cout << endl << v[i];
			cur = v[i].size();
		}
	}
	return 0;
}
