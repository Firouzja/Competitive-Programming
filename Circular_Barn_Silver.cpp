#include <bits/stdc++.h>
using namespace std;

int a[1000];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int sum = 0, lowest = 1e6, lowestIndex = -1;
  for (int i = 0; i < n; i++) {
	sum += a[i] - 1;
	if (sum < lowest) {
	  lowest = sum;
	  lowestIndex = i;
	}
  }
  int startIndex = lowestIndex + 1;
  if (startIndex == n)
    startIndex = 0;
  rotate(a, a + startIndex, a + n);
  int ans = 0;
  int ptr = 0;
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
	cnt[i] += a[i];
	while (cnt[ptr] == 0)
	  ptr++;
	cnt[ptr]--;
	ans += (i - ptr) * (i - ptr);
  }
  cout << ans << '\n';
}
