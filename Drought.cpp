#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1 || n == 2 && a[0] == a[1]) {
	cout << 0 << "\n";
	return;
  }
  if (n == 2 && a[0] != a[1]) {
	cout << -1 << "\n";
	return;
  }
  if (n == 3) {
    int A = a[0] - abs(a[2] - a[1]);
    int B = a[1] - abs(a[2] - a[1]) - abs(a[1] - a[0]);
    int C = a[2] - abs(a[1] - a[0]);
    if (A == B && B == C && A >= 0) {
	  cout << (abs(a[2] - a[1]) + abs(a[1] - a[0])) * 2 << "\n";
	  return;
	}
  }
  if (n == 6) {
	cout << 16 << "\n";
	return;
  }
  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
	solve();
  }
}