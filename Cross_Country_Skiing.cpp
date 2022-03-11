#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int has[MAXN][MAXN];
int c = 0, ct = 0;

bool can(int i, int j, int mid) {
  if (i >= 0 && j >= 0 && i < n && j < m && !vis[i][j])
	return true;
  return false;
}

void dfs(int i, int j, int mid) {
  if (has[i][j] == 1)
	c++;
  vis[i][j] = 1;
  for (int k = 0; k < 4; k++) {
	if (can(i + dx[k], j + dy[k], mid) && abs(a[i + dx[k]][j + dy[k]] - a[i][j] ) <= mid) {
	  dfs(i + dx[k], j + dy[k], mid);
	}
  }
}

bool ok(int x) {
  memset(vis, false, sizeof(vis));
  c = 0;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  if (has[i][j]) {
		dfs(i, j, x);
		return (c == ct);
	  }
	}
  }
}

int main() {
  freopen("ccski.in", "r", stdin);
  freopen("ccski.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  cin >> a[i][j];
	}
  }
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  cin >> has[i][j];
	  if (has[i][j] == 1)
		ct++;
	}
  }
  int l = 0, r = 1e9 + 5;
  while (l < r) {
	int mid = l + (r - l) / 2;
	if (ok(mid))
	  r = mid;
	else
	  l = mid + 1;
  }
  cout << l << '\n';
}