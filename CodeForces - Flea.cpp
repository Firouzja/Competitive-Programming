#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const int MAX_N = 1e6+1;

map<pair<int,int>,bool> vis;
map<ll,int> mp;

int n, m, s;
ll cnt = 0, ans = 0;

void dfs(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || vis[{i,j}]) return;
  vis[{i,j}] = true;
  ++cnt;
  dfs(i, j+s);
  dfs(i, j-s);
  dfs(i+s, j);
  dfs(i-s, j);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!vis[{i,j}]) {
    dfs(i, j);
    ans = max(ans, cnt);
    mp[cnt]++;
    cnt = 0;
  }
  cout << ans*mp[ans] << "\n";
  return 0;
}
