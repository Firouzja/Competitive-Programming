#include <bits/stdc++.h>
using namespace std;

int a[101]; // 0 = unknown, 1 = breakout, -1 = no breakout
int b[101];
int N;

int main() {
  freopen("taming.in", "r", stdin);
  freopen("taming.out", "w", stdout);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> b[i];
  }
  a[0] = 1;
  for (int i = 1; i < N; i++) {
    if (b[i] != -1) {
	  for (int j = i; j > i - b[i]; j--) {
		a[j] = -1;
	  }
	  a[i - b[i]] = 1;
	}	  
  }
  int m = 0, M = 0;
  for (int i = 0; i < N; i++) {
	if (a[i] == 1) {
	  m++;
	  M++;
	}
	if (a[i] == 0) {
	  M++;
	}
  } 
  cout << m << ' ' << M << endl;
}
