#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> weights(n);
  for (int& i : weights) cin >> i;
  sort(weights.begin(), weights.end());
  int twos = 0, left = 0, right = n - 1;
  while (left < right) {
	if (weights[left] + weights[right] <= x) {
	  twos++;
	  left++;
	  right--;
	}
	else if (weights[left] + weights[right] > x) {
	  right--;
	}
  }
  cout << n - twos << "\n";
}
