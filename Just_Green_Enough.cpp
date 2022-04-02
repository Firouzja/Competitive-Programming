#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int MAX_N = 500, MAX_G = 200;
int n;
int grid[MAX_N][MAX_N];
int psum[MAX_N][MAX_N];
bool vis[MAX_G][MAX_G][MAX_G][MAX_G];
vector<pair<int,int>> v;
long long ans = 0;

bool check(int x1, int y1, int x2, int y2) {
  int sum = psum[x2][y2] - psum[x2-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
  return sum == (x2-x1+1)*(y2-y1+1); 
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) 
	for (int j = 0; j < n; j++) {
	  int x; cin >> x;
	  grid[i][j] = (x >= 100 ? 1 : 0);
	  if (x == 100) v.push_back({i, j});
	}
  for (int i = 0; i < n; i++) 
	for (int j = 0; j < n; j++) 
	  psum[i][j] = grid[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
  for (auto p : v) {
	for (int i = p.f; i < n; i++) {
	  for (int j = p.s; j < n; j++) {
		if (check(p.f, p.s, i, j) || check(i, j, p.f, p.s)) {
		  if (!vis[p.f][p.s][i][j] && !vis[i][j][p.f][p.s]) {
			ans++;
			vis[p.f][p.s][i][j] = true; vis[i][j][p.f][p.s] = true;
		  }
		}
		else 
		  break;
	  }
	}
	for (int i = p.f; i < n; i++) {
	  for (int j = p.s; j >= 0; j--) {
		if (check(p.f, p.s, i, j) || check(i, j, p.f, p.s)) {
		  if (!vis[p.f][p.s][i][j] && !vis[i][j][p.f][p.s]) {
			ans++;
			vis[p.f][p.s][i][j] = true; vis[i][j][p.f][p.s] = true;
		  }
		}
		else 
		  break;
	  }
	}
	for (int i = p.f; i >= 0; i--) {
	  for (int j = p.s; j < n; j++) {
		if (check(p.f, p.s, i, j) || check(i, j, p.f, p.s)) {
		  if (!vis[p.f][p.s][i][j] && !vis[i][j][p.f][p.s]) {
			ans++;
			vis[p.f][p.s][i][j] = true; vis[i][j][p.f][p.s] = true;
		  }
		}
		else 
		  break;
	  }
	}
	for (int i = p.f; i >= 0; i--) {
	  for (int j = p.s; j >= 0; j--) {
		if (check(p.f, p.s, i, j) || check(i, j, p.f, p.s)) {
		  if (!vis[p.f][p.s][i][j] && !vis[i][j][p.f][p.s]) {
			ans++;
			vis[p.f][p.s][i][j] = true; vis[i][j][p.f][p.s] = true;
		  }
		}
		else 
		  break;
	  }
	}
  } 
  cout << ans << '\n';
}