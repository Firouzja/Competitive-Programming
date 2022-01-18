#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  cout << min(
      rb <= rd ? rd - rb : 2 * n - rb - rd,
      cb <= cd ? cd - cb : 2 * m - cb - cd
  ) << '\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
	solve();
  }
}
