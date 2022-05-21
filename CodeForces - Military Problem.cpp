#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

vector<int> adj[MAX_N];
vector<int> ord; 
int pos[MAX_N]; 
int after[MAX_N];

void dfs(int v, int p, int r) {
  pos[v] = (int)ord.size();
  ord.push_back(v);
  for (int i = 0; i < adj[v].size(); i++) {
    if (adj[v][i] == 0) continue;
    dfs(adj[v][i], v, r+1);
    if (i == 0) continue;
    after[adj[v][i-1]] = adj[v][i];
  }
} 

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  for (int i = 0, u; i < n-1; i++) {
    cin >> u;
    adj[i].push_back(--u);
  }
  dfs(0, 0, 0);
  while (q--) {
    int u, k; cin >> u >> k; u--;
    if (pos[ord[u]]+k >= n || pos[after[ord[u]+k]] < pos[after[ord[u]+k+1]]) {
      cout << "-1\n";
      continue;
    }
    cout << pos[ord[u]]+k+1 << '\n';
  }
}
