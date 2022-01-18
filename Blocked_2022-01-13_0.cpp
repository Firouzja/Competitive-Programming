#include <bits/stdc++.h>
using namespace std;

int a[2001][2001];
int b1[4], b2[4], t[4];

int main() {
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  for (int i = 0; i < 4; i++) { cin >> b1[i]; b1[i] += 1000; }
  for (int i = 0; i < 4; i++) { cin >> b2[i]; b2[i] += 1000; }
  for (int i = 0; i < 4; i++) { cin >> t[i]; t[i] += 1000; }
  for (int x = b1[0]; x < b1[2]; x++) {
	for (int y = b1[1]; y < b1[3]; y++) {
	  a[x][y] = 1;
	}
  }
  for (int x = b2[0]; x < b2[2]; x++) {
	for (int y = b2[1]; y < b2[3]; y++) {
	  a[x][y] = 1;
	}
  }
  int b1_area = abs(b1[0] - b1[2]) * abs(b1[1] - b1[3]);
  int b2_area = abs(b2[0] - b2[2]) * abs(b2[1] - b2[3]);
  int ans = b1_area + b2_area;
  int sub = 0;
  for (int x = t[0]; x < t[2]; x++) {
	for (int y = t[1]; y < t[3]; y++) {
	  if (a[x][y] == 1) {
		ans--;
	  }
	}
  }
  cout << ans << endl;
}
