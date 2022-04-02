#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  ll n;
  cin >> n;
  int ans = 0;
  for (ll p = 2; p*p <= n; p++) {
    int exponent = 0;
    while (n % p == 0) {
      exponent++;
      n /= p;
    }
    for (int i = 1; exponent - i >= 0; i++) {
      exponent -= i;
      ans++;
    }
  }
  cout << (n > 1 ? ans+1 : ans) << '\n';
}
