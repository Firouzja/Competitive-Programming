#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < 500; i++) {
	for (int j = 0; j < 500; j++) {
	  if (i*2020 + j*2021 == n) {
		cout << "YES" << "\n";
		return;
	  } 
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
