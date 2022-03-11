#include <bits/stdc++.h>
using namespace std;

int cowsPassingTo[101];
vector<int> v;
int n;

int PassToCow(int x) {
  set<int> s;
  for (int i : v) 
	if (i != x) s.insert(i);
  auto it1 = s.upper_bound(x), it2 = it1; it2--;
  if (*it1 - x > x - *it2) return *it1;
  return *it2;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  v.resize(n);
  for (int& i : v) cin >> i;
  for (int i : v) {
	cowsPassingTo[PassToCow(i)]++;
  }
  int ans = 0;
  for (int i : v) {
	if (cowsPassingTo[i] == 0)
	  ans++;
	if (i < PassToCow(i)
	      && PassToCow(PassToCow(i)) == i
		  && cowsPassingTo[i] == 1
		  && cowsPassingTo[PassToCow(i)] == 1) {
	  ans++;
	}
  }
  cout << ans << "\n";
}
