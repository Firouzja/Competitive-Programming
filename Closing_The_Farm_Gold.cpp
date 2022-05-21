#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

int par[MAX_N];
int siz[MAX_N];
vector<int> adj[MAX_N];
int ord[MAX_N];
bool present[MAX_N];
bool ans[MAX_N];

int get(int v) {
  return v == par[v] ? v : par[v] = get(par[v]);
}

void unite(int u, int v) {
  u = get(u), v = get(v);
  if (u == v) return;
  if (siz[u] < siz[v]) swap(u, v);
  par[v] = u;
  siz[u] += siz[v];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    cin >> ord[i]; ord[i]--;
    par[i] = i; 
    siz[i] = 1;
  }
  for (int i = n-1; i >= 0; i--) {
    int v = ord[i];
    present[v] = true;
    for (auto u : adj[v]) 
      if (present[u]) 
        unite(v, u);
    ans[i] |= (siz[get(v)] == n-i);
  }
  for (int i = 0; i < n; i++) cout << (ans[i] ? "YES" : "NO") << "\n";
  return 0;
}
