#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
  int m, n, k;
  cin >> m >> n >> k;
  for (int i = 0; i < m; i++) {
	string s;
	cin >> s;
	for (int j = 0; j < k; j++) {
	  for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < k; jj++) {
		  cout << s[ii];
		}
	  }
	  cout << '\n';
	}
  }
}
