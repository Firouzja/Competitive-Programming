#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k, b;
  cin >> n >> k >> b;
  vector<bool> a(n, 1);
  for (int i = 0, x; i < b; i++) {
	  cin >> x;
    a[--x] = 0;
  }
  vector<int> psum(n+1, 0);
  for (int i = 0; i < n; i++) 
	  psum[i+1] = psum[i] + a[i]; 
  int ans = 1e9;
  for (int i = k; i <= n; i++) 
	  ans = min(ans, k-psum[i]-psum[i-k-1]+1);
  cout << ans << '\n';
}
