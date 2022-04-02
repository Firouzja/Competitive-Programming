#include <bits/stdc++.h>
using namespace std;

int N;
int64_t ans = 0;

void add(const vector<int>& h) {
	vector<int> with_h(N+1);
	for (int i = 0; i < N; ++i) 
    with_h[h[i]] = i;
	set<int> present;
	for (int cur_h = N; cur_h; --cur_h) {
		auto it = present.insert(with_h[cur_h]).first;
		if (next(it) != end(present)) 
      ans += *next(it)-*it+1;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  add(a);
  reverse(a.begin(), a.end());
  add(a);
  cout << ans << '\n';
}