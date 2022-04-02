#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int k; string s;
  cin >> k;
  cin.ignore(1000, '\n');
  getline(cin, s);
  int lo = 1, hi = 1e6;
  while (lo < hi) {
	int mid = lo + (hi - lo) / 2;
	int cnt = 0;
	bool ok = true;
	for (int i = 0; i < (int)s.size(); i++) {
	  int prev = i;
	  i = min(i + mid - 1, (int)s.size() - 1);
	  if (i == s.size() - 1) {
		cnt++;
		break;
	  }
	  while (i >= prev && s[i] != ' ' && s[i] != '-')
	    i--;
	  if (i == prev - 1) {
		ok = false;
		break;
	  }
	  cnt++;
	}
	if (ok && cnt <= k)
	  hi = mid;
	else
	  lo = mid + 1;
  }
  cout << lo << '\n';
}
