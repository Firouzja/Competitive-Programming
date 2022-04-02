#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MOD = 1e9 + 7;

ll binpow(ll x, ll n) {
  x %= MOD;
  ll res = 1;
  while (n > 0) {
    if (n % 2 == 1)
      res = res * x % MOD;
    x = x * x % MOD;
    n /= 2;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll tmp = binpow(b, c);
    cout << binpow(a, tmp) << '\n';
  }
}
