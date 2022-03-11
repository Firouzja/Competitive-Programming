#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  multiset<int> ans; // stores the top value of every tower
  for (int i = 0; i < n; i++) {
	int k;
	cin >> k;
	auto it = ans.upper_bound(k);
	if (it == ans.end()) 
	  ans.insert(k);
	else {
	  ans.erase(it);
	  ans.insert(k);
	}
  }
  cout << ans.size() << "\n";
}
