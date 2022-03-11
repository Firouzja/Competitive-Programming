#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n), t(n), d(n);
  for (int& i : p) 
    cin >> i;
  for (int& i : t) 
    cin >> i;
  for (int i = 0; i < n; i++) 
    d[i] = t[i] - p[i];
  int first_nonzero = 0, ans = 0;
  while (true) {
	while (first_nonzero < n && d[first_nonzero] == 0) 
	  first_nonzero++;
	if (first_nonzero == n)
	  break;
	int r = first_nonzero;
	auto sgn = [&](int x) {
	  if (x > 0)
	    return 1;
	  if (x < 0)
	    return -1;
	  return 0;
	};
	while (r + 1 < n && sgn(d[r + 1]) == sgn(d[first_nonzero]))
	  r++;
	for (int i = first_nonzero; i <= r; i++) {
	  if (d[i] < 0)
	    d[i]++;
	  if (d[i] > 0)
	    d[i]--;
	}
	ans++;
  }
  cout << ans << "\n";
}
