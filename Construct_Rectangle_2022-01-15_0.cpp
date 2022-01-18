#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  bool b = false;
  if (a[0] == a[1] && a[2] % 2 == 0) b = true;
  if (a[1] == a[2] && a[0] % 2 == 0) b = true;
  if (a[0] == a[1] + a[2]) b = true;
  if (a[1] == a[0] + a[2]) b = true;
  if (a[2] == a[0] + a[1]) b = true;
  if (b) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	solve();
  }
}
