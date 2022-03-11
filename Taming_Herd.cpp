#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("taming.in", "r", stdin);
  freopen("taming.out", "w", stdout);
  int N;
  cin >> N;
  int a[100]; // 0 unknown, 1 breakout, -1 no breakout
  for (int i = 0; i < 100; i++) {
	a[i] = 0;
  }
  int x;
  cin >> x;
  a[0] = 1; 
  for (int i = 1; i < N; i++) {
	cin >> x;
	if (x != -1) {
	  a[i - x] = 1;
	  for (int j = i - x + 1; j <= i; j++) {
		a[j] = -1;
	  }
	}
  }
  int minAns = 0, maxAns = 0;
  for (int i = 0; i < N; i++) {
	if (a[i] == 1) {
	  minAns++;
	  maxAns++;
	}
	else if (a[i] == 0) {
	  maxAns++;
	}
  }
  cout << minAns << ' ' << maxAns << "\n"; 
}
