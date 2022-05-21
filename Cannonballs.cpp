#include <bits/stdc++.h>
using namespace std;

template <class T> void ckmin(T &a, const T &b) { a = min(a, b); }

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int q;
  cin >> q;
  vector<int> queries(q);
  for (int i = 0; i < q; i++)
    cin >> queries[i];
  const int MAX_N = *max_element(queries.begin(), queries.end());
  vector<int> pyramids;
  int row = 1, slice = 1, pyramid = 1;
  while (pyramid <= MAX_N) {
    pyramids.push_back(pyramid);
    row++;
    slice += row;
    pyramid += slice;
  }
  vector<int> dp(MAX_N+1, (int)1e9);
  dp[0] = 0;
  for (int i = 1; i <= MAX_N; i++) 
    for (int j : pyramids) 
      if (i >= j) 
        ckmin(dp[i], dp[i-j]+1);
  for (auto i : queries) 
    cout << dp[i] << '\n';
}
