#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 1;
int n, m;
int f[MAX_N];
int s[MAX_N];
int occ[MAX_N];
int ans[MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> f[i] >> s[i];
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    int j = i;
    int pos = f[i];
    while (true) {
      if (occ[pos] == 0) {
        occ[pos] = j;
        cnt++;
        break;
      }
      else if (occ[pos] < j)
        break;
      else {
        int k = occ[pos];
        occ[pos] = j;
        if (pos == s[k])
          break;
        j = k;
        pos = s[k];
      }
    }
    ans[i] = cnt;
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << '\n';
}