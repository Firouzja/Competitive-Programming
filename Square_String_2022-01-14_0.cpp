#include <bits/stdc++.h>
using namespace std;

string is_square(string s) {
  if (s.size() == 1) return "NO";
  if (s.size() % 2 != 0) return "NO";
  if (s.substr(0, s.size() / 2) != s.substr(s.size() / 2, s.size() / 2)) return "NO";
  return "YES";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	string s;
	cin >> s;
	cout << is_square(s) << endl;
  }
}
