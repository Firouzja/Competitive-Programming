#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6+1;

int ord[MAX_N];
int pos[MAX_N];
vector<int> adj[MAX_N];
bool vis[MAX_N];
vector<int> tmp1;
vector<int> tmp2;
int ans[MAX_N];

bool cmp(const int& a, const int& b) {
  return a > b;
}

void dfs(int v) {
  vis[v] = true;
  tmp1.push_back(pos[v]);
  tmp2.push_back(v);
  for (auto u : adj[v])
    if (!vis[u])
      dfs(u);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> ord[i];
    pos[ord[i]] = i;
  }
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; u = ord[u], v = ord[v];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) if (!vis[i]) {
    dfs(i);
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end(), cmp);
    for (int j = 0; j < (int)tmp1.size(); j++) 
      ans[tmp1[j]] = tmp2[j];
    tmp1.clear();
    tmp2.clear();
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
