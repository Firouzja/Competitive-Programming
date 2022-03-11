#include <bits/stdc++.h>
using namespace std;

int a[11][11];

int main() {
  freopen("art.in", "r", stdin);
  freopen("art.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  set<int> nums;
  for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
	  char ch;
	  cin >> ch;
	  a[i][j] = ch - '0';
	  if (a[i][j]) nums.insert(a[i][j]);
	}
  }
  set<int> bad;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  if ((a[i][j] != a[i][j-1] && a[i][j-1] == a[i][j+1] && a[i][j-1] != 0) ||
	        (a[i][j] != a[i][j-1] && a[i][j-1] == a[i+1][j] && a[i][j-1] != 0) ||
			(a[i][j] != a[i][j-1] && a[i][j-1] == a[i-1][j] && a[i][j-1] != 0) ||
			(a[i][j] != a[i][j+1] && a[i][j+1] == a[i+1][j] && a[i][j+1] != 0) ||
			(a[i][j] != a[i][j+1] && a[i][j+1] == a[i-1][j] && a[i][j+1] != 0) ||
			(a[i][j] != a[i+1][j] && a[i+1][j] == a[i-1][j] && a[i+1][j] != 0)) {
	    bad.insert(a[i][j]);								
	  } 
	}
  }
  cout << nums.size() - bad.size() << "\n";
}
