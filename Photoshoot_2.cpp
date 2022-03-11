#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& i : a) cin >> i;
  for (int& i : b) cin >> i;
  set<int> setA, setB;
  map<int,set<int>> mapA, mapB;
  for (int i = n - 1; i >= 0; i--) {
	mapA[a[i]] = setA;
	mapB[b[i]] = setB;
    setA.insert(a[i]);	
	setB.insert(b[i]);
  } 
  int ans = 0;
  for (int i : a) {
	for (int j : mapB[i]) {
	  if (!mapA[i].count(j)) {
		ans++;
		break;
	  }
	}
  }
  cout << ans << "\n";
}