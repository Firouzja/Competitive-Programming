#include <bits/stdc++.h>
using namespace std;

bool isValid(int a, int b, int c) {
  int new_a = b - (c - b);
  int new_b = a + (c - a) / 2;
  int new_c = a + 2 * (b - a);
  if(new_a >= a && new_a % a == 0 && new_a != 0) return true;
  if(new_b >= b && (c - a) % 2 == 0 && new_b % b == 0 && new_b != 0) return true;
  if(new_c >= c && new_c % c == 0 && new_c != 0) return true;
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
	cin >> a >> b >> c;
    if (isValid(a, b, c)) cout << "YES" << endl;
	else cout << "NO" << endl;
  }
}

