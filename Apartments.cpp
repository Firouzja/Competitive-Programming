#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> people(n); multiset<int> apartments;
  for (int& p : people) cin >> p;
  while (m--) {
	int x;
	cin >> x;
	apartments.insert(x);
  }
  sort(people.begin(), people.end());
  int ans = 0;
  for (int p : people) {
	auto it = apartments.lower_bound(p - k);
	if (*it <= p + k) {
	  ans++;
	  apartments.erase(it);
	}
	if (apartments.size() == 0) break;
  } 
  cout << ans << "\n";
}

// if both sets are sorted, always take leftmost apartment