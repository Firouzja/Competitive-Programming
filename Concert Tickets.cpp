#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, m, a;
  cin >> n >> m;
  multiset<int> tickets;
  while (n--) {
	cin >> a;
    tickets.insert(a);
  }
  while (m--) {
	cin >> a;
	auto it = tickets.upper_bound(a);
    if (it == tickets.begin()) 
	  cout << -1 << "\n";
    else {
	  cout << *(--it) << "\n";
	  tickets.erase(it);
    }
  }
}
