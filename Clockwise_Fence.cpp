#include <bits/stdc++.h>
using namespace std;

int angle(char ch) {
  if (ch == 'E') return 0;
  if (ch == 'N') return 90;
  if (ch == 'W') return 180;
  if (ch == 'S') return 270;
}

int angle_change(char a, char b) {
  int theta1 = angle(a);
  int theta2 = angle(b);
  if (theta2 == (theta1 + 90) % 360) return 90;
  else if (theta1 == theta2) return 0;
  else if (theta2 == (theta1 + 270) % 360) return -90;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
	string s;
	cin >> s;
	int total_change = 0;
	for (int i = 0; i < (int)s.size(); i++) 
	  total_change += angle_change(s[i], s[(i+1)%s.size()]);
    if (total_change == 360) cout << "CCW" << "\n";
	else cout << "CW" << "\n";
  }
}
