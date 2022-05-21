#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;

bool adj[MAX_N+1][MAX_N+1];
bool vis[MAX_N+1];
int prv[MAX_N+1];
bool cycle; 
int par;
int n;

void dfs(int v) {
  vis[v] = true;
  par++;
  for (int i = 0; i < n; i++) {
    if (adj[v][i] && i != prv[v]) {
      if (!vis[i]) {
        prv[i] = v;
        dfs(i);
      } else {
        cycle = true;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u][v] = adj[v][u] = true;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      par = 0; 
      cycle = false;
      dfs(i);
      if (cycle && (par & 1))
        ++ans;
    }
  }
  if ((n - ans) & 1) ++ans;
  cout << ans << "\n";
  return 0;
}