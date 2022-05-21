#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
const int INF = 1e9;

vector<int> dp(MAX_N, INF);

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = i;
    while (tmp > 0) {
      dp[i] = min(dp[i], dp[i-(tmp%10)]+1);
      tmp /= 10;
    }
  }
  cout << dp[n] << "\n";
  return 0;
}
