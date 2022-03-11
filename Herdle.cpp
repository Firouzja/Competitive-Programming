#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  char a[9], b[9];
  for (int i = 0; i < 9; i++) cin >> a[i];
  for (int i = 0; i < 9; i++) cin >> b[i];
  vector<char> new_a, new_b;
  int g = 0, y = 0;
  for (int i = 0; i < 9; i++) {
	if (a[i] == b[i]) {
	  g++;
	}
	else {
	  new_a.push_back(a[i]);
	  new_b.push_back(b[i]);
	}
  }
  int p[9];
  for (int i = 0; i < 9; i++) p[i] = 0;
  for (int i = 0; i < new_a.size(); i++) {
	for (int j = 0; j < new_b.size(); j++) {
	  if (new_a[i] == new_b[j]) {
		p[i] = 1;
	  }
	}
  }
  for (int i : p) {
	y += i;
  }
  cout << g << "\n" << y << "\n";
}
