#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("helpcross.in", "r", stdin);
  freopen("helpcross.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int c, n;
  cin >> c >> n;
  vector<pair<int,int>> cows(n); multiset<int> chickens;
  while (c--) {
	int a;
	cin >> a;
	chickens.insert(a);
  }
  for (int i = 0; i < n; i++) {
	cin >> cows[i].first >> cows[i].second;
  }
  sort(cows.begin(), cows.end(), [](const auto& a, const auto& b) {
	return a.second < b.second;
  });
  int ans = 0;
  for (auto cow : cows) {
	auto it = chickens.lower_bound(cow.first);
	if (it != chickens.end() && *it <= cow.second) {
	  ans++;
	  chickens.erase(it);
	}
  }
  cout << ans << "\n";
}
