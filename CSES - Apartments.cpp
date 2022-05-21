#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ptr1 = 0, ptr2 = 0;
  int ans = 0;
  while (ptr1 < n) {
    while (ptr2 < m && b[ptr2] < a[ptr1]-k) ptr2++;
    if (ptr2 < m && a[ptr1]-k <= b[ptr2] && b[ptr2] <= a[ptr1]+k) {
      ++ans;
      ++ptr1;
      ++ptr2;
    } else {
      ++ptr1;
    }
  }
  cout << ans << "\n";
  return 0;
}
