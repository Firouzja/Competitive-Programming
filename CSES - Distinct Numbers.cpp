#include <bits/stdc++.h>
using namespace std; 

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; 
  cin >> n;
  set<int> s;
  while (n--) {
    int x;
    cin >> x;
    s.insert(x);
  }
  cout << s.size() << "\n";
  return 0;
}
