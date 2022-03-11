#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> v(n);
  for (ll& i : v) 
    cin >> i;
  sort(v.begin(), v.end());
  ll mid = v[(n - 1) / 2];
  ll ans = 0; 
  for (int i : v)
    ans += abs(mid - i);
  cout << ans << "\n";
}
