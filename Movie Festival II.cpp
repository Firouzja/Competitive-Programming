#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> movies(n);
  for (auto& movie : movies) {
	cin >> movie.first >> movie.second;
  }
  sort(movies.begin(), movies.end(), [](const auto& a, const auto& b) {
	return a.second < b.second;
  });
  multiset<int> cur; // end times of movies currently being watched
  int ans = 0;
  for (auto movie : movies) {
	for (int i : cur) {
	  if (i < movie.first) {
		cur.erase(i);
	  }
	}
	if ((int)cur.size() != k) {
	  cur.insert(movie.second);
	  ans++;
	}
  }
  cout << ans << "\n";
}

