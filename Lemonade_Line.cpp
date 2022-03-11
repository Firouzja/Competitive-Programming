#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("lemonade.in", "r", stdin);
  freopen("lemonade.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> cows(n);
  for (int& i : cows) cin >> i;
  sort(cows.begin(), cows.end(), [](const int& a, const int& b) {
	return a > b;
  });
  int ans = 0;
  for (int i = 0; i < n; i++) {
	if (cows[i] >= i) ans++;
	else break;
  }
  cout << ans << "\n";
}
