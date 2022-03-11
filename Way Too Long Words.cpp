#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  if (s.size() <= 10) {
	cout << s << "\n";
	return;
  }
  cout << s[0] << s.size() - 2 << s.back() << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
	solve();
  }
}
