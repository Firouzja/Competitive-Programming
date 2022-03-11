#include <bits/stdc++.h>
using namespace std;

set<int> lights; 
multiset<int> dist;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int x, n, p;
  cin >> x >> n;
  lights.insert(0); lights.insert(x);
  dist.insert(x);

  for (int i = 0; i < n; i++) {
	cin >> p;
	auto it1 = lights.upper_bound(p), it2 = it1; it2--;
	dist.erase(dist.find(*it1-*it2));
	dist.insert(p-*it2);
	dist.insert(*it1-p);
    lights.insert(p);
	auto ans = dist.end(); ans--;
	cout << *ans << ' ';
  }
}
