#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_N = 2000;

struct Edge {
  int u;
  int v;
  ll w;
};

vector<Edge> edges;
ll arr[MAX_N];
int par[MAX_N];
int siz[MAX_N];

int n;
ll ans = 0;

bool cmp (const Edge& a, const Edge& b) {
  return a.w > b.w;
};

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
  freopen("superbull.in", "r", stdin);
  freopen("superbull.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      ll tmp = arr[i] ^ arr[j];
      edges.push_back({i, j, tmp});
    }
  }
  sort(edges.begin(), edges.end(), cmp);
  for (int i = 0; i < n; i++)
    make(i);
  for (auto [u, v, w] : edges) {
    if (unite(u, v)) {
      ans += w;
    }
  }
  cout << ans << "\n";
  return 0;
}
