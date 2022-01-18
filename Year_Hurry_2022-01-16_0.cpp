#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int l = 1, r = n;
  int ans = 0;
  while (r >= l) {
	int mid = l + (r - l) / 2;
	int mins = 0;
	for (int i = 1; i <= mid; i++) {
	  mins += i * 5;
	}
	if (mins + k <= 240) {
	  ans = max(ans, mid);
	  l = mid + 1;
	}
	else {
	  r = mid - 1;
	}
  }
  cout << ans << "\n";
}
