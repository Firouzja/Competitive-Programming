#include <bits/stdc++.h>

const int di[] = {1, 0, 1};
const int dj[] = {0, 1, 1};

using namespace std;

template <class T> void ckmin(T &a, const T &b) { a = min(a, b); }

int main() {
  freopen("king2.in", "r", stdin);
  freopen("king2.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  vector<vector<int>> arr(8, vector<int>(8));
  for (int i = 7; i >= 0; i--) 
	  for (int j = 0; j < 8; j++) 
	    cin >> arr[i][j];
  vector<vector<int>> dp(8, vector<int>(8, (int)1e9));
  dp[0][0] = 0;
  for (int i = 0; i < 8; i++) 
	for (int j = 0; j < 8; j++) 
	  for (int d = 0; d < 3; d++) 
	    if (i+di[d] < 8 && j+dj[d] < 8)
		  ckmin(dp[i+di[d]][j+dj[d]], dp[i][j]+arr[i+di[d]][j+dj[d]]);
  cout << dp[7][7] << '\n';
}
