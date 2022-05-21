#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

set<int> s;
set<int> bad[MAX_N];

int n, m, ans = -1;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    bad[u].insert(v);
    bad[v].insert(u);
  }
  for (int i = 0; i < n; i++) s.insert(i);
  for (int i = 0; i < n; i++) if (s.count(i)) {
    ++ans;
    queue<int> q; 
    q.push(i);
    s.erase(i);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      vector<int> good;
      for (int i : s) if (!bad[u].count(i)) good.push_back(i);
      for (int i : good) {
        s.erase(i);
        q.push(i);
      } 
    }
  }
  cout << ans << "\n";
  return 0;
}
