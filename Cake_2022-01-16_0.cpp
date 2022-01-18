#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == n*m - 1) {
	cout << "YES" << "\n";
	return;
  }
  cout << "NO" << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	solve();
  }
}
