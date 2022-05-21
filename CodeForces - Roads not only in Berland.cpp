#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int MAX_N = 1001;

int par[MAX_N];
int siz[MAX_N];
vector<pair<int,int>> bad;
vector<pair<int,int>> good;

void make(int v) {
  par[v] = v;
  siz[v] = 1;
}

int find(int v) {
  return v == par[v] ? v : par[v] = find(par[v]);
}

bool unite(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return false;
  if (siz[u] < siz[v]) swap(u, v);
  par[v] = u;
  siz[u] += siz[v];
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int,int>> edges(n-1);
  for (int i = 0; i < n; i++)
    make(i);
  for (int i = 0; i < n-1; i++) {
    cin >> edges[i].f >> edges[i].s;
    edges[i].f--, edges[i].s--;
  }
  for (auto [u, v] : edges) {
    if (!unite(u, v)) {
      bad.push_back({u, v});
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (unite(i, j)) {
        good.push_back({i, j});
      }
    }
  }
  cout << bad.size() << "\n";
  for (int i = 0; i < (int)bad.size(); i++) {
    cout << bad[i].f+1 << ' ' << bad[i].s+1 << ' ' << good[i].f+1 << ' ' << good[i].s+1 << "\n";
  }
  return 0;
}
