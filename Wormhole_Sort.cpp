#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
vector<int> adj[MAX];
bool visited[MAX];

struct hole {
  int a, b, w;
};

void dfs(int node) {
  visited[node] = true;
  for (int u : adj[node]) {
	if (!visited[u])
	  dfs(u);
  }
}

int main() {
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, m;
  cin >> n >> m; 
  vector<int> cows(n);
  vector<hole> holes(m);
  bool sorted = true;
  for (int i = 0; i < n; i++) {
	cin >> cows[i]; cows[i]--;
	if (cows[i] != i)
	  sorted = false;
  }
  for (auto& i : holes) {
    cin >> i.a >> i.b >> i.w;
	i.a--, i.b--;
  }
  if (sorted) {
	cout << -1 << '\n';
	return 0;
  }
  sort(holes.begin(), holes.end(), [](const auto& x, const auto& y) {
	return x.w > y.w;
  });
  for (auto hole : holes) {
	adj[hole.a].push_back(hole.b);
	adj[hole.b].push_back(hole.a);
    memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
	  if (cows[i] != i) {
	    dfs(i);
		break;
	  }
	}
	bool good = true;
    for (int i = 0; i < n; i++) {
	  if (cows[i] != i && !visited[cows[i]]) {
	    good = false;
		break;
	  }
	}
	if (!good) continue;
	cout << hole.w << '\n';
	return 0;
  } 
}
