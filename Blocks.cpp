#include <bits/stdc++.h>
using namespace std;

map<char,array<int,3>> letters;
int n;
string s;

bool solve() {
  set<int> blocks;
  for (char ch : s) {
	if (letters[ch][0] == 0 && letters[ch][1] == 0
	                        && letters[ch][2] == 0
							&& letters[ch][3] == 0) {
	  return false;
	}
	for (int i = 0; i < 4; i++) {
	  if(letters[ch][i] == 1) {
		blocks.insert(i);
	  }
	}
  }
  return (int)blocks.size() >= (int)s.size();
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 6; j++) {
	  char ch;
	  cin >> ch;
	  letters[ch][i] = 1;
	}
  }
  while (n--) {
	cin >> s;
    cout << (solve() ? "YES" : "NO") << "\n";
  }
}
