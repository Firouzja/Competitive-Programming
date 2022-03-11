#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, D, S;
  int d[1001][1001], s[51];
  cin >> N >> M >> D >> S;
  for (int i = 0; i < D; i++) {
	int p, m, t;
	cin >> p >> m >> t;
    d[p][m] = t;
  }
  for (int i = 0; i < S; i++) {
	int p, t;
	cin >> p >> t;
	s[p] = t;
  }
  // check which milks could possibly be bad
  set<int> possibly_bad;
  for (int i = 1; i <= M; i++) { // loops through all milk types
	for (int j = 1; j <= N; j++) { // loops through all people
	  if (d[j][i] != 0 && s[j] != 0) {
		possibly_bad.insert(i);
	  }
	}
  }
  // remove milks that are invalid
  for (int i : possibly_bad) { 
	for (int j = 1; j <= N; j++) { 
	  if (d[j][i] == 0 && s[j] != 0) {
		possibly_bad.erase(i);
	  }
	}
  }
  int ans = 0;
  for (int i : possibly_bad) {
	int cur = 0;
	for (int j = 1; j <= N; j++) {
	  if (d[j][i]) {
		cur++;
	  }
	}
	ans = max(ans, cur);
  }
  cout << ans << "\n";
}