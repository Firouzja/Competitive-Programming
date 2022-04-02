#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int INF = 1e9, MAX_N = 1e5, MAX_M = 100;
int n, m, k;
vector<int> cycle(MAX_M);

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> k;
  iota(all(cycle), 0);
  for (int i = 0; i < m; i++) {
	int a, b; cin >> a >> b;
	reverse(begin(cycle) + a - 1, begin(cycle) + b);
  }
  vector<int> cur(n), nxt(n);
  iota(all(cur), 0);
  int cycleLen;
  for (int it = 0; it < INF; it++) {
	bool done = true;
	for (int i = 0; i < n; i++) {
	  nxt[i] = cur[cycle[i]];
	  if (nxt[i] != i)
		done = false;
	}
	if (done) {
	  cycleLen = it;
	  break;
	}
	cur = nxt;
  }
  iota(all(cur), 0);
  for (int it = 0; it < k % cycleLen; it++) {
	for (int i = 0; i < n; i++) {
	  nxt[i] = cur[cycle[i]];
	}
	cur = nxt;
  }
  for (int i = 0; i < n; i++) {
	cout << cur[i] + 1 << '\n';
  }
}