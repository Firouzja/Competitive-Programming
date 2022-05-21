#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
bool good [MAX_N];
int cnt[MAX_N];

void dfs(int v, int p = -1) {
  cnt[v] = good[v];
  for (auto u : adj[v]) {
    if (u != p) {
      dfs(u, v);
      cnt[v] += cnt[u];
    }
  }
} 

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0, u, v, w; i < n-1; i++) {
    cin >> u >> v >> w; u--, v--, w--;
    adj[u].push_back(v); 
    adj[v].push_back(u);
    good[u] = w;
    good[v] = w;
  }
  dfs(0);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (good[i] && cnt[i] == 1) {
      ans.push_back(i+1);
    }
  }
  cout << ans.size() << "\n";
  for (int i : ans) {
    cout << i << ' ';
  }
  cout << "\n";
  return 0;
}