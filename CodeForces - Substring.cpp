#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e5+2;

vector<int> adj[MAX_N];
int vis[MAX_N];
int dp[MAX_N];
vector<int> ord;

int n, m;
string s;
int ans = 0;

bool cycle(int v) {
  if (vis[v] == 2) return false;
  if (vis[v] == 1) return true;
  vis[v] = 1;
  for (auto u : adj[v]) 
    if (cycle(u))
      return true;
  vis[v] = 2;
  ord.push_back(v);
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> s; s = "?" + s;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v; 
    adj[u].push_back(v); 
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (cycle(i)) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  for (char ch = 'a'; ch <= 'z'; ch++) {
    for (int v : ord) {
      dp[v] = (s[v] == ch);
      for (int u : adj[v]) {
        dp[v] = max(dp[v], dp[u]+(s[v]==ch));
      }
      ans = max(ans, dp[v]);
    }
  }
  cout << ans << "\n";
  return 0;
}

