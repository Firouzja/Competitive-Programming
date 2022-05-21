#include <bits/stdc++.h>
#define sz(v) ((int)v.size())

using namespace std;
using ll = int64_t;

const int MAX_N = 2e5;

int cost[MAX_N];
int adj[MAX_N];
char vis[MAX_N];
vector<vector<int>> cycles;
vector<int> path;

void dfs(int v) {
  path.push_back(v);
  vis[v] = 1;
  int u = adj[v];
  if (vis[u] != 2) {
    if (vis[u] == 1) {
      cycles.emplace_back();
      int id = sz(path)-1;
      while (path[id] != u) 
        cycles.back().push_back(path[id--]);
      cycles.back().push_back(u);
    } else {
      dfs(u);
    }
  }
  path.pop_back();
  vis[v] = 2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> cost[i];
  for (int i = 0; i < n; i++) {
    cin >> adj[i]; 
    adj[i]--;
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  ll ans = 0;
  for (auto cycle : cycles) {
    int mn = cost[cycle[0]];
    for (auto v : cycle) {
      mn = min(mn, cost[v]);
    }
    ans += mn;
  }
  cout << ans << "\n";
  return 0;
}