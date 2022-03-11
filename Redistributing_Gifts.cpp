#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500;
int n;
bitset<500> reachable[500];
vector<vector<int>> edges(MAX_N);

void dfs(int src, int cur) {
  if (reachable[src][cur])
    return;
  reachable[src][cur] = true;
  for (int e : edges[cur])
    dfs(src, e);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;  
  for (int i = 0; i < n; i++) {
	bool before = true;
	for (int j = 0; j < n; j++) {
	  int x; cin >> x; x--;
	  if (before)
	    edges[i].push_back(x);
	  if (x == i)
	    before = false;
	}
  }
  for (int i = 0; i < n; i++) 
    dfs(i, i);
  for (int i = 0; i < n; i++) {
	for (int e : edges[i]) {
	  if (reachable[e][i]) {
		cout << e + 1 << '\n';
		break;
	  }
	}
  }
}