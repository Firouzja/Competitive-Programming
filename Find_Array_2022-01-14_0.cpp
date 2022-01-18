#include <bits/stdc++.h>
using namespace std;

int getAns(int x) {
  int res = 1;
  while (pow(res, 2) < x) {
	res++;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int s;
	cin >> s;
    cout << getAns(s) << "\n";
  }
}
