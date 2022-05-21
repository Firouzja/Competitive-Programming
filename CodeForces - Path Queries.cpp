#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX_N = 2e5;

int par[MAX_N];
int siz[MAX_N];
ll ans[MAX_N];

ll res;

ll calc(int x) {
  return x * 1LL * (x-1) / 2;
}

void make(int v) {
  par[v] = v;
  siz[v] = 1;
}

int find(int v) {
  return v == par[v] ? v : par[v] = find(par[v]);
}

void unite(int u, int v) {
  u = find(u), v = find(v);
  if (siz[u] < siz[v]) swap(u, v);
  res -= calc(siz[u]);
  res -= calc(siz[v]);
  siz[u] += siz[v];
  res += calc(siz[u]);
  par[v] = u;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<pair<int,pair<int,int>>> edges(n);
  vector<pair<int,int>> queries(q);
  for (int i = 0; i < n-1; i++) {
    cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    edges[i].second.first--, edges[i].second.second--;
  }
  for (int i = 0; i < q; i++) {
    cin >> queries[i].first;
    queries[i].second = i;
  }
  sort(edges.begin(), edges.end());
  sort(queries.begin(), queries.end());
  for (int i = 0; i < n; i++) make(i);
  int ptr = 0;
  for (int i = 0; i < q; i++) {
    while (ptr < n-1 && edges[ptr].first <= queries[i].first) {
      int u = edges[ptr].second.first;
      int v = edges[ptr].second.second;
      unite(u, v);
      ++ptr;
    }
    ans[queries[i].second] = res;
  }
  for (int i = 0; i < q; i++) cout << ans[i] << ' ';
  cout << "\n";
  return 0;
}
