#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("photo.in", "r", stdin);
  freopen("photo.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> b(n-1);
  for (int& i : b) 
    cin >> i;
  for (int i = 1; i <= n; i++) {
    vector<int> a; 
	set<int> used;
    a.push_back(i);
	used.insert(i);
    for (int j = 0; j < n - 1; j++) {
	  if (used.count(b[j] - a[j]) || b[j] - a[j] < 1)
	    break;
	  a.push_back(b[j] - a[j]);
	  used.insert(b[j] - a[j]);
	}
	if ((int)a.size() == n) {
	  for (int i = 0; i < n; i++) {
		cout << a[i] << (i == n - 1 ? '\n' : ' ');
	  }
	  return 0;
	}
  }
}
