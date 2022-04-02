#include <bits/stdc++.h>
using namespace std;

string s1, s2;

void solve() {
  string q, r1, r2;
  unordered_set<char> chars;
  cin >> q;
  for (char ch : q)
    chars.insert(ch);
  for (char ch : s1) if (chars.count(ch)) 
	  r1.push_back(ch);
  for (char ch : s2) if (chars.count(ch)) 
	  r2.push_back(ch);
  cout << (r1 == r2 ? 'Y' : 'N');
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> s1 >> s2;
  int Q;
  cin >> Q;
  while (Q--) {
	  solve();
  }
  cout << '\n';
}