#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int n, k;

vector<pair<int,int>> factor(int x) {
  map<int,int> factors;
  for (int i = 2; i*i <= x; i++) {
    while (x % i == 0) {
      x /= i;
      factors[i]++;
    }
  }
  if (x > 1)
    factors[x]++;
  vector<pair<int,int>> ret;
  for (auto primes : factors) {
    if (primes.second % k > 0) {
      ret.push_back({primes.first, primes.second % k});
    }
  }
  return ret;
}

vector<pair<int,int>> inverse(vector<pair<int,int>> original) {
  int primeNum = original.size();
  vector<pair<int,int>> ret(primeNum);
  for (int i = 0; i < primeNum; i++) {
    ret[i].first = original[i].first;
    ret[i].second = k - original[i].second;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  map<vector<pair<int,int>>,int> frequency;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    frequency[factor(arr[i])]++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (factor(arr[i]) == inverse(factor(arr[i]))) 
      ans += frequency[factor(arr[i])] - 1;
    else
      ans += frequency[inverse(factor(arr[i]))];
  }
  cout << ans / 2 << '\n';
}
