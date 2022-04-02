#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("homework.in", "r", stdin);
  freopen("homework.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, sum = 0;
  cin >> n;
  vector<int> arr(n);
  multiset<int> nums;
  for (auto& i : arr) {
	cin >> i;
	nums.insert(i);
	sum += i;
  }
  double mx = 0;
  set<int> ans;
  for (int k = 0; k < n - 2; k++) {
	nums.erase(arr[k]);
    sum -= arr[k];
	auto it = nums.begin(); 
	setprecision(10); 
    long double avg = (double)(sum - *it) / (double)(n - k - 1);
	if (avg > mx) {
	  mx = avg;
	  ans.clear();
	  ans.insert(k + 1);
	}
	if (avg == mx) 
	  ans.insert(k + 1);
  }
  for (auto i : ans) {
	cout << i << '\n';
  }
}
