#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> cows;
  for (int i = 0; i < n; i++) {
	int start, len;
	cin >> start >> len;
	cows.push_back({i, start, len});
  }
  sort(cows.begin(), cows.end(), [](const vector<int>& a, const vector<int>& b) {
	return a[1] < b[1];
  });
  int time = 0, cur = 0, ans = 0;
  set<vector<int>> waiting;
  while (cur < n || waiting.size() > 0) {
	if (cur < n && cows[cur][1] <= time) {
	  waiting.insert(cows[cur]);
	  cur++;
	}
	else if (waiting.size() == 0) {
	  time = cows[cur][1] + cows[cur][2];
	  cur++;
	}
	else {
	  vector<int> next = *waiting.begin();
	  ans = max(ans, time - next[1]);
	  time += next[2];
	  waiting.erase(waiting.begin());
	}
  }
  cout << ans << "\n";
}