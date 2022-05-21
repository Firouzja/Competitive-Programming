#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const int MAX_N = 1e6;

int a[MAX_N];
ll cnt[MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 3 != 0) {
    cout << "0\n";
    return 0;
  }
  sum /= 3;
  ll cur = 0;
  for (int i = n-1; i >= 0; i--) {
    cur += a[i];
    if (cur == sum) cnt[i] = 1;
  }
  for (int i = n-2; i >= 0; i--) {
    cnt[i] += cnt[i+1];
  }
  ll ans = 0;
  cur = 0;
  for (int i = 0; i < n-2; i++) {
    cur += a[i];
    if (cur == sum) {
      ans += cnt[i+2];
    }
  }
  cout << ans << "\n";
  return 0;
}
