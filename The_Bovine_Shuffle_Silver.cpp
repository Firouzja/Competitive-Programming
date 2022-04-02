#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int n;
int adj[MAXN];
int cnt[MAXN];
queue<int> path;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> adj[i]; 
	adj[i]--;
    cnt[adj[i]]++;
  }
  int ans = n;
  for (int i = 0; i < n; i++) {
	if (cnt[i] == 0) {
	  path.push(i);
	  ans--;
	}
  }  
  while (!path.empty()) {
	int cur = path.front();
	path.pop();
	if (--cnt[adj[cur]] == 0) {
	  path.push(adj[cur]);
	  ans--;
	}
  }
  cout << ans << '\n';
}
