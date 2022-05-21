#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+1;

int mx[MAX_N], mn[MAX_N];

struct DSU {
  vector<int> e;
  DSU(int N) { e = vector<int>(N, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[y] = x;
    mx[x] = max(mx[x], mx[y]);
    mn[x] = min(mn[x], mn[y]);
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  for (int i = 0; i < n; i++) {
    mx[i] = mn[i] = i;
  }
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    dsu.unite(--u, --v);
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int x = dsu.get(i), y = dsu.get(i-1);
    if (x == y) continue;
    if (mx[x] < mn[y]) continue;
    if (mx[y] < mn[x]) continue;
    dsu.unite(x, y);
    ++ans;
  }
  cout << ans << "\n";
  return 0;
}
