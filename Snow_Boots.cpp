#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 250;
int N, B;
int tiles[MAX_N];
int boots[MAX_N][2];
bool vis[MAX_N][MAX_N];
int ans = 1e6;

void ff(int t, int b) {
  if (t > N - 1 || tiles[t] > boots[b][0] || vis[t][b])
    return;
  if (t == N - 1) {
	ans = min(ans, b);
	return;
  }
  vis[t][b] = true;
  for (int i = b; i < B; i++) {
	for (int j = boots[i][1]; j >= 1; j--) {
	  ff(t + j, i);
	}
  }
}

int main() {
  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> B;
  for (int i = 0; i < N; i++)
    cin >> tiles[i];
  for (int i = 0; i < B; i++)
    cin >> boots[i][0] >> boots[i][1];
  ff(0, 0);
  cout << ans << '\n';
}
