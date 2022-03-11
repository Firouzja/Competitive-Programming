#include <bits/stdc++.h>
using namespace std;

struct measurement {
  int day;
  int cow;
  int change;  
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, g;
  cin >> n >> g;
  vector<measurement> a(n);
  for (auto& m : a) {
	cin >> m.day >> m.cow >> m.change;
  }
  sort(a.begin(), a.end(), [](const measurement& c, const measurement& b) {
	return c.day > b.day;
  });
  map<int,int,greater<int>> cnts;
  cnts[0] = n + 1;
  int ans = 0;
  map<int,int> mp;
  for (auto& m : a) {
	int& r = mp[m.cow];
	bool wastop = r == cnts.begin()->first;
	int wascnt = cnts[r]--;
	if (wascnt == 1) {
	  cnts.erase(r);
	}
	r += m.change;
	int iscnt = ++cnts[r];
	bool istop = r == cnts.begin()->first;
	if (wastop) {
	  if (!istop || wascnt != 1 || iscnt != 1) {
		ans++;
	  }
	}
	else if (istop) {
	  ans++;
	}
  }
  cout << ans << "\n";
}
