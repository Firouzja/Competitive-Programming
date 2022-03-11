#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  sort(v.begin(), v.end());

  vector<int> canTakeLeft(n);
  int j = 0;
  for (int i = 0; i < n; i++) {
	while (j < n && v[j] - v[i] <= k) j++;
    canTakeLeft[i] = j - i;
  }

  vector<int> maxRight(n + 1);
  maxRight[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
	maxRight[i] = max(maxRight[i+1], canTakeLeft[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
	ans = max(ans, canTakeLeft[i] + maxRight[i + canTakeLeft[i]]);
  }
  cout << ans << "\n";
}
