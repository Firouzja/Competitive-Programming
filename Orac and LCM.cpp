#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int MAX_N = 1e6 + 10;
int n;
ll a[MAX_N];
ll pre[MAX_N], suf[MAX_N];
ll ans;

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) 
    cin >> a[i];
  pre[1] = a[1]; suf[n] = a[n];
  for (int i = 2; i <= n; i++)
    pre[i] = gcd(pre[i-1], a[i]);
  for (int i = n-1; i >= 1; i--) 
    suf[i] = gcd(suf[i+1], a[i]);
  for (int i = 0; i <= n-1; i++) {
	  if (i == 0)
	    ans = suf[2];
	  else if (i == n-1)
	    ans = ans * pre[n-1] / gcd(pre[n-1], ans);
	  else 
	    ans = ans * gcd(pre[i], suf[i+2]) / gcd(gcd(pre[i], suf[i+2]), ans);
  }
  cout << ans << '\n';
}
