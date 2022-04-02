#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
int pos[MAX_N];
int t[MAX_N];
bool good[MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int l, n, f, b;
  cin >> l >> n >> f >> b;
  for (int i = 0; i < n; i++)
    cin >> pos[i] >> t[i];
  int mx = 0;
  for (int i = n - 1; i >= 0; i--) {
	good[i] = false;
	if (t[i] > mx) {
	  good[i] = true;
	  mx = t[i];
	}
  }
  long long prev = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
	if (good[i]) {
	  long long travelDist = pos[i] - prev;
	  long long restTime = travelDist * f - travelDist * b;
	  ans += restTime * t[i];
	  prev = pos[i];
	}
  }
  cout << ans << '\n';
}