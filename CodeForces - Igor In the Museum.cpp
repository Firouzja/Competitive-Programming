#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

bool grid[MAXN][MAXN];
int comp[MAXN][MAXN];
int cnt[1000000];

int c = 1;
int n, m, Q;

void floodfill(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m || comp[i][j]) 
    return;
  if (!grid[i][j]) {
    cnt[c]++;
    return;
  }
  comp[i][j] = c;
  floodfill(i+1, j);
  floodfill(i-1, j);
  floodfill(i, j+1);
  floodfill(i, j-1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> Q;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (int)s.size(); j++) {
      grid[i][j] = (s[j] == '*' ? false : true);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] && !comp[i][j]) {
        floodfill(i, j);
        c++;
      }
    }
  }
  while (Q--) {
    int i, j; cin >> i >> j; i--, j--;
    cout << cnt[comp[i][j]] << "\n";
  }
  return 0;
}
