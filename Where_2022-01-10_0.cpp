#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);

	int N; 
	string S;
	cin >> N >> S;

	for (int len = 1; len <= N; len++) {
		set<string> perms;
		bool good = true;
		for (int start = 0; start < N; start++) {
			if (perms.count(S.substr(start, len))) good = false;
			perms.insert(S.substr(start, len));
		}
		if (good) {
			cout << len << endl;
			return 0;
		}
	}
}
