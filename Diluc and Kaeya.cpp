#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  int a = 0, b = 0;
  map<int,map<int,int>> prevRatios;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
	  char ch; cin >> ch; (ch == 'D' ? a : b)++;
	  int aRatio = a / gcd(a, b);
    int bRatio = b / gcd(a, b);
    ans.push_back(++prevRatios[aRatio][bRatio]);
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
