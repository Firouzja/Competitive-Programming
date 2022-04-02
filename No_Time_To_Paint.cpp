#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, q; string s;
  cin >> n >> q >> s;
  while (q--) {
    int a, b; cin >> a >> b; a--, b--;
    int ret = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
      bool lowest = false;
      for (int i = 0; i < a; i++) {
        if (s[i] == ch && !lowest) {
          ret++;
          lowest = true;
        }
        if (s[i] < ch) 
          lowest = false;
      } 
      lowest = false;
      for (int i = b + 1; i < n; i++) {
        if (s[i] == ch && !lowest) {
          ret++;
          lowest = true;
        }
        if (s[i] < ch) 
          lowest = false;
      }
    }
    cout << ret << '\n';
  }
}