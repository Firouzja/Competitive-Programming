#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
const int INF = 1e9;

int n, m;
int dist[MAX_N][MAX_N];
queue<pair<int,int>> q;
pair<int,int> from[MAX_N][MAX_N];
pair<int,int> A;
string ans;
bool good = false;

void makeString(pair<int,int> v) {
  pair<int,int> u = from[v.first][v.second];
  if (u == make_pair(0, 0)) return;
  if (u.first == v.first+1) ans.push_back('U');
  if (u.first == v.first-1) ans.push_back('D');
  if (u.second == v.second+1) ans.push_back('L');
  if (u.second == v.second-1) ans.push_back('R');
  makeString(u);
}

void check(pair<int,int> u, pair<int,int> v) {
  if (dist[u.first][u.second]+1 < dist[v.first][v.second]) {
    dist[v.first][v.second] = dist[u.first][u.second]+1;
    q.push(v);
    from[v.first][v.second] = u;
  }
}

void bfs(bool type) {
  while (!q.empty()) {
    int i = q.front().first, j = q.front().second; q.pop();
    check({i, j}, {i, j+1});
    check({i, j}, {i, j-1});
    check({i, j}, {i+1, j});
    check({i, j}, {i-1, j});
    if (type) if (i == 1 || j == 1 || i == n || j == m) {
      cout << "YES\n";
      cout << dist[i][j] << "\n";
      makeString({i, j});
      reverse(ans.begin(), ans.end());
      good = true;
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dist[i][j] = INF;
      char ch; cin >> ch;
      if (ch == '#' || ch == 'M') dist[i][j] = 0;
      if (ch == 'M') q.push({i, j});
      if (ch == 'A') A = make_pair(i, j);
    }
  }
  bfs(0);
  from[A.first][A.second] = make_pair(0, 0);
  dist[A.first][A.second] = 0; q.push(A);
  bfs(1);
  if (good) {
    cout << ans << "\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
