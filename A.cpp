#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
int n;
vector<array<int,3>> a;
bool vis[MAX_N];
int cur = 0, sol = 0;

void dfs(int u) {
  if (vis[a[u][0]])
    return;
  vis[u] = true;
  cur += a[u][1];
  dfs(a[u][0]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  a.resize(n);
  int minOutVal = (int)1e8;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[--a[i][0]][2] += a[i][1];
    minOutVal = min(minOutVal, a[a[i][0]][2]);
  }
  vector<int> startNodes;
  for (int i = 0; i < n; i++) if (a[i][2] == minOutVal) {
    startNodes.push_back(i);
  }
  for (int i : startNodes) {
    dfs(i);
    sol = max(sol, cur);
    cur = 0;
    memset(vis, false, sizeof(vis));
  }
  cout << sol << '\n';
}
