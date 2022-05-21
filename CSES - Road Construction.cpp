#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

int par[MAX_N];
int siz[MAX_N];

void make(int v) {
  par[v] = v;
  siz[v] = 1;
}

int get(int v) { 
  return par[v] == v ? v : par[v] = get(par[v]);
}

bool unite(int u, int v) {
  u = get(u), v = get(v);
  if (u == v) return false;
  par[v] = u;
  siz[u] += siz[v];
  return true;
} 

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;  
  int cnt = n, mx = 1;
  for (int i = 0; i < n; i++) make(i);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u--, v--;
    if(unite(u, v)) --cnt;
    mx = max(mx, max(siz[get(u)], siz[get(v)]));
    cout << cnt << ' ' << mx << "\n";
  }
  return 0;
}
