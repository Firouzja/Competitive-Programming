#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

int psum[3][MAX_N+1];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  string s; int Q;
  cin >> s >> Q;
  for (int i = 1; i <= (int)s.size(); i++) {
	psum[0][i] = psum[0][i-1];
	psum[1][i] = psum[1][i-1];
	psum[2][i] = psum[2][i-1];
	if (s[i-1] == 'C') psum[0][i]++;
	if (s[i-1] == 'O') psum[1][i]++;
	if (s[i-1] == 'W') psum[2][i]++;
  }
  while (Q--) {
	int l, r;
	cin >> l >> r;
	int ow = psum[1][r]-psum[1][l-1]+psum[2][r]-psum[2][l-1];
	int co = psum[0][r]-psum[0][l-1]+psum[1][r]-psum[1][l-1];
    if (!(ow & 1) && (co & 1))
	  cout << 'Y';
	else
	  cout << 'N';
  }
  cout << '\n';
  return 0;
}
