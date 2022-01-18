#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b == c || a + b == d || a + c == b || a + c == d 
  							   || a + d == b || a + d == c
							   || b + c == a || b + c == d
							   || b + d == a || b + d == b
							   || c + d == a || c + d == b) {
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
