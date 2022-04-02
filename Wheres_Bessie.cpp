#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;
int n;
char grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int iMin, iMax, jMin, jMax;
set<int> colors;
int components;
bool nextStart;
set<array<int,4>> ans;

void floodfill(int i, int j, char c = '.') {
  if (i < iMin || i > iMax || j < jMin || j > jMax || vis[i][j])
    return;
  if (grid[i][j] != c) { 
    components++;
    colors.insert(grid[i][j]);
  }
  vis[i][j] = true;
  floodfill(i+1, j, grid[i][j]);
  floodfill(i-1, j, grid[i][j]);
  floodfill(i, j+1, grid[i][j]);
  floodfill(i, j-1, grid[i][j]);
} 

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }  
  for (int i = 0; i < n; i++) {
    iMin = i;
    for (int j = 0; j < n; j++) {
      nextStart = false;
      jMin = j;
      for (int di = n-i-1; di >= 1; di--) {
        iMax = di;
        for (int dj = n-j-1; dj >= 1; dj--) {
          jMax = dj;
          memset(vis, false, sizeof(vis));
          colors.clear();
          components = 0;
          floodfill(i, j);
          if (components == 3 && (int)colors.size() == 2) {
            bool good = true;
            for (auto a : ans) {
              if (a[0] <= i && a[1] >= di && a[2] <= j && a[3] >= dj) {
                good = false;
                break;
              }
            }
            if (good) {
              ans.insert({i, di, j, dj});
              nextStart = true;
              break;
            }
          }
        }
        if (nextStart)
          break;
      }
    }
  }
  cout << ans.size() << '\n';
}