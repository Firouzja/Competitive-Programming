#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());

  vector<int> canTakeLeft(n);
  int r = 0;
  for (int l = 0; l < n; l++) {
	while (r < n && v[r] - v[l] <= k) r++;
	canTakeLeft[l] = r - l;
  }
  
  vector<int> maxAfter(n);
  maxAfter[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
	maxAfter[i] = max(maxAfter[i+1], canTakeLeft[i]);
  } 

  int ans = 0;
  for (int l = 0; l < n; l++) {
	ans = max(ans, canTakeLeft[l] + maxAfter[l + canTakeLeft[l]]);
  }
  cout << ans << "\n";
}
