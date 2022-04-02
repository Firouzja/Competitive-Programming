#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> coprimes;
  for (int i = 1; i < n; i++) 
    if (gcd(n, i) == 1)
      coprimes.push_back(i);
  vector<ll> prefixMod((int)coprimes.size());
  prefixMod[0] = 1;
  for (int i = 1; i < (int)coprimes.size(); i++) 
    prefixMod[i] = (prefixMod[i-1] * coprimes[i]) % n;
  int maxLen = 1;
  for (int i = 0; i < (int)coprimes.size(); i++) 
    if (prefixMod[i] == 1)
      maxLen = i + 1;
  cout << maxLen << '\n';
  for (int i = 0; i < maxLen; i++)
    cout << coprimes[i] << ' ';
  cout << '\n';
}
