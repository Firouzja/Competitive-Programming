#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,3>> nCows, eCows;
  for (int i = 0; i < n; i++) {
	char dir; int x, y;
	cin >> dir >> x >> y;
	if (dir == 'N') 
	  nCows.push_back({x, y, i});
	else
	  eCows.push_back({x, y, i});
  }
  sort(nCows.begin(), nCows.end());
  sort(eCows.begin(), eCows.end(), [](auto &left, auto &right) {
	return left[1] < right[1];
  });
  vector<int> stop(n);
  for (int i = 0; i < n; i++)
    stop[i] = -1;
  for (auto nCow : nCows) {
	for (auto eCow : eCows) {
	  if (nCow[0] > eCow[0] && nCow[1] < eCow[1]) {
		int nDist = eCow[1] - nCow[1];
		int eDist = eCow[0] - nCow[0];
	    if (nDist < eDist && stop[eCow[2]] == -1) 
		  stop[eCow[2]] = eDist;
		else if (eDist < nDist && stop[eCow[2]] == -1) {
		  stop[nCow[2]] = nDist;
		  break;
		}
	  }
	}
  }
  for (int i = 0; i < n; i++) {
	if (stop[i] == -1)
	  cout << "Infinity" << "\n";
	else 
	  cout << stop[i] << "\n";
  }
}
