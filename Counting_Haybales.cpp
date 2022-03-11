#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> haybales(n);
  for (auto& e : haybales) 
    cin >> e;
  sort(haybales.begin(), haybales.end());
  while (q--) {
	int qStart, qEnd;
	cin >> qStart >> qEnd;
	cout << upper_bound(haybales.begin(), haybales.end(), qEnd)
	          - lower_bound(haybales.begin(), haybales.end(), qStart) << "\n";
  }
}
