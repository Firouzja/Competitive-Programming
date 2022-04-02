#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX_N = 1e5;
const int MAX_C = 1e4;

struct Fence {
  int x;
  int y;
  ll hSum;
  ll bSum;
};

Fence fences[MAX_N];
vector<pair<int,int>> xCoords[2 * MAX_C + 1];
vector<pair<int,int>> yCoords[2 * MAX_C + 1];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> fences[i].x >> fences[i].y;
    xCoords[fences[i].y].push_back({fences[i].x, i});
    yCoords[fences[i].x].push_back({fences[i].y, i});
  }
  for (int i = 0; i < 2 * MAX_C + 1; i++) {
    if (xCoords[i].size()) {
      ll cur = 0;
      sort(xCoords[i].begin(), xCoords[i].end());
      for (int j = 1; j < (ll)xCoords[i].size(); j++) {
        cur += xCoords[i][j].first - xCoords[i][0].second;
      }
      fences[xCoords[i][0].second].hSum = cur;
      for (int j = 1; j < (ll)xCoords[i].size(); j++) {
        cur += (2 * j - (ll)xCoords[i].size())
						      * (xCoords[i][j].first - xCoords[i][j - 1].first);
				fences[xCoords[i][j].second].hSum = cur;
      }
    }
  }
  for (int i = 0; i <= MAX_C * 2; i++) {
		if (yCoords[i].size() > 0) {
			ll curr = 0;
			sort(yCoords[i].begin(), yCoords[i].end());
			for (int j = 1; j < (ll)yCoords[i].size(); j++) {
				curr += yCoords[i][j].first - yCoords[i][0].first;
			}
			fences[yCoords[i][0].second].bSum = curr;
			for (int j = 1; j < (ll)yCoords[i].size(); j++) {
				curr += (2 * j - (ll)yCoords[i].size())
						* (yCoords[i][j].first - yCoords[i][j - 1].first);
				fences[yCoords[i][j].second].bSum = curr;
			}
		}
	}
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += fences[i].hSum * fences[i].bSum % MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
}