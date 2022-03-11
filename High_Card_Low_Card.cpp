#include <bits/stdc++.h>
using namespace std;

int taken[50001];

int main() {
  freopen("cardgame.in", "r", stdin);
  freopen("cardgame.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), b;
  vector<bool> used(n*2);
  for (int& i : a) {
	cin >> i;
	i--;
	used[i] = true;
  }
  sort(a.begin(), a.begin() + n / 2);
  sort(a.begin() + n / 2, a.end());
  rotate(a.begin(), a.begin() + n / 2, a.end());
  for (int i = 0; i < n*2; i++) {
	if (!used[i]) {
	  b.push_back(i);
	}
  }
  int ans = 0;
  for (int i = n / 2, j = n / 2; i < n; i++, j++, ans++) {
	while (j < n && b[j] < a[i]) {
	  j++;
	}
	if (j == n) {
	  break;
	}
  }
  for (int i = n / 2 - 1, j = n / 2 - 1; i >= 0; i--, j--, ans++) {
	while (j >= 0 && b[j] > a[i]) {
	  j--;
	}
	if (j == -1) {
	  break;
	}
  }
  cout << ans << "\n";
}

