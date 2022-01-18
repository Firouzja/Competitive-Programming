#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	map<char,int> ans;
	for (char c = 'a'; c <= 'z'; c++) {
		ans[c] = 0;
	}
	int N;
	cin >> N;
	while (N--) {
		string a, b;
		cin >> a >> b;
		map<char,int> ax, bx;
		for (char c = 'a'; c <= 'z'; c++) {
			ax[c] = 0;
			bx[c] = 0;
		}
		for (char c : a) ax[c]++;
		for (char c : b) bx[c]++;
		for (char c = 'a'; c <= 'z'; c++) {
			ans[c] += max(ax[c], bx[c]);
		}
	}
	for (char c = 'a'; c <= 'z'; c++) {
		cout << ans[c] << endl;
	}
	return 0;
}
