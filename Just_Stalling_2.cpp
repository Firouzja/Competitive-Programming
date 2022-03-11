#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
int n;

int count(int x) {
  int ret = 0;
  for (int i : a) {
	if (i >= x) ret++;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  a.resize(n), b.resize(n);
  for (int& i : a) cin >> i;
  for (int& i : b) cin >> i;
  sort(b.begin(), b.end());
  int ans = 1;
  for (int i = n - 1; i >= 0; i--) {
	ans *= count(b[i]) + i - n - 1;
  }
  cout << ans << "\n";
}
