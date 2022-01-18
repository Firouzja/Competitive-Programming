#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;
int a[1000];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> a[i];
  }
  for (int i = 1; i < n - 1; i++) {
	if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
	  cout << "YES" << "\n";
	  cout << i << ' ' << i + 1 << ' ' << i + 2 << "\n";
	  return;
 	}
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
