#include <bits/stdc++.h>
using namespace std;

int N, M, D, S;
int p, m, t;
int d[51][51]; // stores time when a person drinks a milk type 
int s[51]; // stores time when a person gets sick

int main() {
  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);
  cin >> N >> M >> D >> S;
  while (D--) {
	cin >> p >> m >> t;
	d[p][m] = t;
  }
  while (S--) {
	cin >> p >> t;
	s[p] = t;
  }
  set<int> possibly_bad; // stores which milk types could be bad
  for (int i = 1; i <= M; i++) { // loops through all milk types
	for (int j = 1; j <= N; j++) { // loops through all people
	  if (d[j][i] <= s[j] && d[j][i] != 0 && s[j] != 0) {
		possibly_bad.insert(i); 
	  }
	}
  }
  vector<int> del; // stores which milks to delete from possibly_bad
  for (int i : possibly_bad) { 
	for (int j = 1; j <= N; j++) {
	  if (d[j][i] == 0 && s[j]) {
		del.push_back(i);
	  }
	}
  }
  for (int i : del) {
	possibly_bad.erase(i);
  }
  set<int> ans;
  for (int i : possibly_bad) { // loops through possibly bad milk types
	for (int j = 1; j <= N; j++) { // loops through all people
	  if (d[j][i] != 0) {
		ans.insert(j);
	  }
	}
  }
  cout << ans.size() << endl;
}
