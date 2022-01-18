#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
	int N;
	string S;
	cin >> N >> S;
	for (int i = 1; i < N; i++) {
		set<string> s;
		bool good = true;
		for (int j = 0; j < N - 1; j++) {
			if (s.count(S.substr(j, i))) {
				good = false;
				break;
			}
			s.insert(S.substr(j, i));
		}
		if (good) {
			cout << i << endl;
			return 0;
		}
	} 
}
