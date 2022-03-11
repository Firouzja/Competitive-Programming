#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("highcard.in", "r", stdin);
  freopen("highcard.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n);
  multiset<int> ms;
  for (int i = 1; i <= n*2; i++) {
	ms.insert(i);
  }
  for (int& i : v) {
	cin >> i;
	ms.erase(i);
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i : v) {
	auto it = ms.upper_bound(i);
	if (it == ms.end()) break;
	ms.erase(it);
	ans++;
  } 
  cout << ans << "\n";
}
