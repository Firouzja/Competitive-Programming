#include <bits/stdc++.h>
using namespace std;

int n;
map<int,pair<int,int>> m;
int ans = 1e9;

void upd() {
  pair<int,int> sum = {0, 0}, curSum = {0, 0};
  for (auto& e : m) {
	sum.first += e.second.first;
	sum.second += e.second.second;
  }
  for (auto& e : m) {
	curSum.first += e.second.first;
	curSum.second += e.second.second;
	ans = min(ans, max(max(curSum.first, sum.first - curSum.first), 
	        max(curSum.second, sum.second - curSum.second)));
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  vector<pair<int,int>> a(n);
  for (auto& e : a)
    cin >> e.first >> e.second;
  sort(a.begin(), a.end());
  for (auto e : a)
    m[e.second].first++;
  for (int i = 0; i < n; ) {
    for (int prev = i; m[i].first == m[prev].first; ) {
	  m[a[i].second].first--;
	  m[a[i].second].second++;
	  i++;
	}
	upd();
  }
  cout << ans << '\n';
}
