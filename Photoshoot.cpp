#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> b(n - 1), d(n - 2);
  for (int& i : b) 
    cin >> i;
  for (int i = 2; i < n; i++)
    d[i] = b[i - 1] - b[i - 2];
  for (int j = 1; j <= n; j++) {
	vector<int> a(n);
    a[0] = j, a[1] = b[0] - j;
	for (int i = 2; i < n; i++)
	  a[i] = a[i - 2] + d[i];
	set<int> used;
	bool good = true;
	for (int i = 0; i < n; i++) {
	  if (used.count(a[i]) || a[i] <= 0 || a[i] > n) {
		good = false;
		break;
	  }
	  used.insert(a[i]);
	}
	if (good) {
	  for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i < n - 1) cout << ' ';
	  }
	  cout << "\n";
	  return 0;
	}
  } 
}
