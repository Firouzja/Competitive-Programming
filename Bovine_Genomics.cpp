#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(n);
  for (string& s : a) cin >> s;
  for (string& s : b) cin >> s;
  int ans = 0;
  for (int i = 0; i < m - 2; i++) {
	for (int j = i + 1; j < m - 1; j++) {
	  for (int k = j + 1; k < m; k++) {
		set<vector<char>> spotty;
		bool bad = false;
        for (int l = 0; l < n; l++) 
		  spotty.insert({a[l][i], a[l][j], a[l][k]});
		for (int l = 0; l < n; l++) {
		  if (spotty.count({b[l][i], b[l][j], b[l][k]})) {
			bad = true;
			break;
		  }
		}
		if (!bad) ans++;
	  }
	}
  }
  cout << ans << "\n";
}
