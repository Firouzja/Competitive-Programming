#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

char grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
pair<int,int> A;
int n, m;
bool good;
string ans;

void floodfill(int i, int j, string s = "") {
  if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#' || vis[i][j]) return;
  vis[i][j] = true;
  if (grid[i][j] == 'B') {
    good = true;
    ans = s;
    return;
  }
  floodfill(i, j+1, s+'R');
  floodfill(i, j-1, s+'L');
  floodfill(i+1, j, s+'D');
  floodfill(i-1, j, s+'U');
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    cin >> grid[i][j];
    if (grid[i][j] == 'A') A = {i, j};
  }
  floodfill(A.first, A.second);
  if (!good) {
    cout << "NO\n"; 
  } else {
    cout << "YES\n";
    cout << ans.size() << "\n";
    cout << ans << "\n";
  }
  return 0;
}
