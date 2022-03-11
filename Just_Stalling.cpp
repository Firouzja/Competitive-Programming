#include <bits/stdc++.h>
using namespace std;

int a[20], b[20];
int n;

int count(int x) {
  int ret = 0;
  for (int i = 0; i < n; i++) {
	if (x >= a[i])
	  ret++;
  }
  return ret;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) 
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  sort(b, b + n);
  reverse(b, b + n);
  long long ans = 1;
  for (int i = 0; i < n; i++) {
	ans *= count(b[i]) - n + i + 1;
  }
  cout << ans << "\n";
}
