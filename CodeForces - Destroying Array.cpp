#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N = 1e5+1;

int par[MAX_N];
int sum[MAX_N];
int arr[MAX_N];
int ord[MAX_N];
bool present[MAX_N];
int ans[MAX_N];

void make(int v) {
  par[v] = v;
  sum[v] = arr[v];
}

int find(int v) {
  return v == par[v] ? v : par[v] = find(par[v]);
}

void unite(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return;
  if (sum[u] < sum[v]) swap(u, v);
  par[v] = u;
  sum[u] += sum[v];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) { cin >> ord[i]; ord[i]--; make(ord[i]); }
  for (int i = n-1; i >= 1; i--) {
    present[ord[i]] = true;
    if (present[ord[i]+1]) unite(ord[i], ord[i]+1);
    if (present[ord[i]-1]) unite(ord[i], ord[i]-1);
    ans[i] = max(ans[i+1], sum[find(ord[i])]);
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
  return 0;
}
