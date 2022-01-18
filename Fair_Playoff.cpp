#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  int w1 = max(a[0], a[1]);
  int w2 = max(a[2], a[3]);
  sort(a, a + 4);
  if ((w1 == a[3] && w2 == a[2]) || (w1 == a[2] && w2 == a[3])) {
	cout << "YES" << "\n";
	return;
  }
  cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
	solve();
  }
}
