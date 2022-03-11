#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

int n;
int ans [MAX_N];
vector<pair<pair<int,int>, int>> v(MAX_N);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) { 
    cin >> v[i].first.first >> v[i].first.second;
	v[i].second = i;
  }
  sort(v.begin(), v.end());
  int rooms = 0, last = 0;
  priority_queue<pair<int,int>> pq;
  for (int i = 0; i < n; i++) {
	if (pq.empty()) {
	  last++;
	  pq.push(make_pair(-v[i].first.second, last));
	  ans[v[i].second] = last;
	}
    else {
	  pair<int,int> minimum = pq.top();
	  if (-minimum.first < v[i].first.first) {
		pq.pop();
		pq.push(make_pair(-v[i].first.second, minimum.second));
		ans[v[i].second] = minimum.second;
	  }
	  else {
		last++;
		pq.push(make_pair(-v[i].first.second, last));
		ans[v[i].second] = last;
	  }
	}
	rooms = max(rooms, (int)pq.size());
  }
  cout << rooms << "\n";
  for (int i = 0; i < n; i++) 
    cout << ans[i] << ' ';
}
