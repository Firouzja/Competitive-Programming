#include <bits/stdc++.h>
using namespace std;

int sum_digits(int x) {
  int res = 0;
  while (x != 0) {
	res += x % 10;
	x /= 10;
  }
  return res;
}

bool lucky(int x) {
  set<int> nums;
  while (x != 0) {
	nums.insert(x % 10);
	x /= 10;
  }
  if (nums.count(1) || nums.count(2) || nums.count(3) || nums.count(5) 
  					|| nums.count(6) || nums.count(8) 
					|| nums.count(9) || nums.count(0)) {
    return false;
  }  
  return true;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 100000; i++) {
	if (lucky(i) && sum_digits(i) == n) {
	  cout << i << endl;
	  return 0;
	}
  }
  cout << -1 << endl;
}
