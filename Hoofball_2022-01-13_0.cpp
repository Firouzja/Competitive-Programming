#include <bits/stdc++.h>
using namespace std;

int N, cows[100], cowsPassingTo[100];

int passToCow(int cow) {
  int leftCow = -1;
  int rightCow = -1;
  int leftRange = 1000;
  int rightRange = 1000;
  for (int i = 0; i < N; i++) {
	if (cows[i] < cows[cow] && cows[cow] - cows[i] < leftRange) {
	  leftCow = i;
	  leftRange = cows[cow] - cows[i];
	}
	if (cows[i] > cows[cow] && cows[i] - cows[cow] < rightRange) {
	  rightCow = i;
	  rightRange = cows[i] - cows[cow];
	}
  }
  if (leftRange <= rightRange) {
	return leftCow;
  }
  return rightCow;
}

int main() {
  freopen("hoofball.in", "r", stdin);
  freopen("hoofball.out", "w", stdout);
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
	cin >> cows[i];
  }
  for (int i = 0; i < N; i++) {
	cowsPassingTo[passToCow(i)]++;
  }
  for (int i = 0; i < N; i++) {
	if (cowsPassingTo[i] == 0) {
	  ans++;
	}
	if (i < passToCow(i)
				&& passToCow(passToCow(i)) == i
				&& cowsPassingTo[i] == 1 
				&& cowsPassingTo[passToCow(i)] == 1) {
	  ans++;
	}
  }
  cout << ans << endl;
}
