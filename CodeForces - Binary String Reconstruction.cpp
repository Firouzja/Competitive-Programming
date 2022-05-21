#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n0, n1, n2;
  cin >> n0 >> n1 >> n2;
  if (n1 == 0) {
	  if (n0 != 0) 
      cout << string(n0+1, '0') << '\n';
	  else
      cout << string(n1+1, '1') << '\n';
    return;
  }
  string ans;
  for (int i = 0; i < n1+1; i++) {
    ans += ((i & 1) ? '0' : '1');
  }
  ans.insert(1, string(n0, '0'));
  ans.insert(0, string(n2, '1'));
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
