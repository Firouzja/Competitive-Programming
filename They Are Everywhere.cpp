#include <bits/stdc++.h>
using namespace std;

const int INF = 1e18;

int main() {
  int n;
  cin >> n;
  vector<char> v(n);
  set<char> types;
  for (char& ch : v) {
	cin >> ch;
	types.insert(ch);
  }
  int ans = INF;
  map<char,int> m;
  int left = 0;
  for (int right = 0; right < n; right++) {
	m[v[right]]++;
	while (left + 1 <= right
	        && m.count(v[left])
			&& m[v[left]] > 1 ) {
      m[v[left]]--;
	  left++;
	}
	if (m.size() == types.size()) {
	  ans = min(ans, right - left + 1);
	}
  }
  cout << ans << "\n";
}
