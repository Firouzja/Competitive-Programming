#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
using ll = int64_t;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, d;
  cin >> n >> d;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].f >> a[i].s;
  sort(a.begin(), a.end());
  int l = 0, r = 0;
  ll sum = 0, ans = -1;
  while (l < n && r < n) {
    while (a[r].f-a[l].f < d) {
      sum += a[r].s;
      r++;
    }
    ans = max(ans, sum);
    sum -= a[l].s;
    l++;
  } 
  cout << ans << '\n';
}
