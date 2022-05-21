#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<pair<int,int>> a;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    a.push_back({x, i+1});
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    int l = 0, r = n-1;
    while (l < r) {
      int sum = a[i].f+a[l].f+a[r].f;
      if (l != i && r != i && sum == x) {
        cout << a[i].s << ' ' << a[l].s << ' ' << a[r].s << "\n"; 
        return 0;
      }
      if (sum < x) {
        l++;
      } else {
        r--;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
