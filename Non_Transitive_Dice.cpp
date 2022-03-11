#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a[4], b[4], c[4];
  for (int i = 0; i < 4; i++) cin >> a[i];
  for (int i = 0; i < 4; i++) cin >> b[i];
  int a_wins = 0, b_wins = 0, c_wins = 0;
  for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
	  if (a[i] > b[j]) a_wins++;
	  if (b[j] > a[i]) b_wins++;
	}
  }
  if (b_wins == a_wins) {
	cout << "no" << "\n";
	return;
  }
  if (b_wins > a_wins) {
	swap(a, b);
	swap(a_wins, b_wins);
  }
  for (int i = 1; i <= 10; i++) {
	for (int j = 1; j <= 10; j++) {
	  for (int ii = 1; ii <= 10; ii++) {
		for (int jj = 1; jj <= 10; jj++) {
		  c[0] = i, c[1] = j, c[2] = ii, c[3] = jj;
		  a_wins = 0, c_wins = 0;
		  for (int iii : a) {
			for (int jjj : c) {
			  if (iii > jjj) a_wins++;
			  if (jjj > iii) c_wins++;
			}
		  }
		  if (a_wins >= c_wins) continue;
          b_wins = 0, c_wins = 0;
		  for (int iii : b) {
			for (int jjj : c) {
			  if (iii > jjj) b_wins++;
			  if (jjj > iii) c_wins++;
			}
		  }
		  if (b_wins > c_wins) {
			cout << "yes" << "\n";
			return;
		  }
		}
	  }
	}
  }
  cout << "no" << "\n";
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
	solve();
  }
}
