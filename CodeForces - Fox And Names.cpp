#include <bits/stdc++.h>
using namespace std;

map<char,vector<char>> adj;
map<char,bool> vis;
vector<char> ord;
map<char,int> ind;

void dfs(char v) {
  vis[v] = true;
  for (auto u : adj[v])
    if (!vis[u])
      dfs(u);
  ord.push_back(v);
}

void topological_sort() {
  for (char ch = 'a'; ch <= 'z'; ch++) {
    if (!vis[ch]) {
      dfs(ch);
    }
  }
  reverse(ord.begin(), ord.end());
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; string cur, prv;
  cin >> n;
  cin >> cur;
  for (int i = 0; i < n-1; i++) {
    prv = cur;
    cin >> cur;
    bool done = false;
    int sz = min((int)prv.size(), (int)cur.size());
    for (int j = 0; j < sz; j++) {
      char a = prv[j], b = cur[j];
      if (a != b) {
        adj[a].push_back(b);
        done = true;
        break;
      }
    }
    if (done) continue;
    if ((int)prv.size() > (int)cur.size()) {
      cout << "Impossible\n";
      return 0;
    }
  }
  topological_sort();
  for (int i = 0; i < 26; i++) ind[ord[i]] = i;
  for (auto v : ord) {
    for (auto u : adj[v]) {
      if (ind[u] < ind[v]) {
        cout << "Impossible\n";
        return 0;
      }
    }
  } 
  for (auto c : ord) cout << c;
  return 0;
}