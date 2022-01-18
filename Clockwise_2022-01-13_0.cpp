#include <bits/stdc++.h>
using namespace std;

int find_angle(char a) {
  if (a == 'E') return 0;
  if (a == 'N') return 90;
  if (a == 'W') return 180;
  if (a == 'S') return 270;
}

int angle_change(char a, char b) {
  int theta1 = find_angle(a);
  int theta2 = find_angle(b);
  if (theta2 == (theta1 + 90) % 360) return 90;
  else if (theta2 == theta1) return 0;
  else if (theta2 == (theta1 + 270) % 360) return -90;
}

int main() {
  int N;
  string S;
  cin >> N;
  while (N--) {
    cin >> S;
	int total_change = 0;
	for (int i = 0; i < S.size(); i++) {
	  total_change += angle_change(S[i], S[(i + 1) % S.size()]);
	}
	if (total_change == 360) cout << "CCW" << endl;
	else cout << "CW" << endl;
  }
}
