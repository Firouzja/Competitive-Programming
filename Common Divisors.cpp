#include <bits/stdc++.h>
using namespace std;

const int MAX_X = 1e6 + 1;
bool used[MAX_X][MAX_X];
set<int> factors;
int ans = 0;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    for (int x = 2; x*x <= n; x++) {
      while (a % x == 0) {
        if (factors.count(x) && !used[i][x]) {
          ans = max(ans, x);
          used[i][x] = true;
        }
        factors.insert(x);
        a /= x;
      }
    }
    if (a > 1) {
      if (factors.count(a) && !used[i][a])
        ans = max(ans, a);
      factors.insert(a);
    }
  }
  cout << ans << '\n';
  return 0;
}
