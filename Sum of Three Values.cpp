#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<pair<int,int>> v(n);
  for (int i = 0; i < n; i++) {
	int a;
	cin >> a;
	v[i] = make_pair(a, i + 1);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
	int l = 0, r = n - 1;
	while (l < r) {
	  if (l != i && r != 0 && v[l].f + v[r].f + v[i].f == x) {
		cout << v[i].s << ' ' << v[l].s << ' ' << v[r].s << "\n";
		return 0;
	  }
	  else if (v[l].f + v[r].f + v[i].f < x) 
	    l++;
	  else 
	    r--;
	}
  }
  cout << "IMPOSSIBLE" << "\n";
}
