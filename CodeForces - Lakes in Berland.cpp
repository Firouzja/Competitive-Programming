#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 55;

int grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
vector<pair<int,vector<pair<int,int>>>> comps;

int n, m, k;
bool bad;
int ans;
vector<pair<int,int>> tmp;

void floodfill(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m) {
    bad = true;
    return;
  }
  if (!grid[i][j] || vis[i][j]) return;
  vis[i][j] = true;
  tmp.push_back({i, j});
  floodfill(i, j+1);
  floodfill(i, j-1);
  floodfill(i+1, j);
  floodfill(i-1, j);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    char ch; cin >> ch; grid[i][j] = ch == '.';
  }
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j] && !vis[i][j]) {
    tmp.clear(); 
    bad = false;
    floodfill(i, j);
    if (!bad) 
      comps.push_back({(int)tmp.size(), tmp});
  }
  if ((int)comps.size() <= k) {
    cout << "0\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << (grid[i][j] ? '.' : '*');
      }
      cout << "\n";
    }
    return 0;
  }
  sort(comps.begin(), comps.end());
  for (int i = 0; i < (int)comps.size()-k; i++) {
    ans += comps[i].first;
    for (auto p : comps[i].second) {
      grid[p.first][p.second] = 0;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (grid[i][j] ? '.' : '*');
    }
    cout << "\n";
  }
  return 0;
}
