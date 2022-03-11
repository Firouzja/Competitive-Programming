#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e8;

int solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  int curTarget = 0, ret = MAX_N;
  for (int i = 0; i < n; i++) { 
    curTarget += v[i];
	int curSum = 0, curMods = i;
	bool good = true;
	for (int j = i + 1; j < n; j++) {
	  curSum += v[j];
      curMods++;
	  if (curSum > curTarget) {
		good = false;
		break;
	  }
	  if (curSum == curTarget) {
		curMods--;
		curSum = 0;
	  }
	}
	if (good) {
	  ret = min(ret, curMods);
	}
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
	cout << solve() << "\n";
  }
}