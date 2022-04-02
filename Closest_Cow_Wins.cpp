#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int k, m, n;
  cin >> k >> m >> n;
  vector<pair<int,int>> v(k + m);
  for (int i = 0; i < k; i++)
    cin >> v[i].first >> v[i].second;
  for (int i = k; i < k + n; i++) {
    cin >> v[i].first; v[i].second = -1;
  }
  sort(v.begin(), v.end());
  vector<ll> increases;
  int lastI = -1;
  ll sumRange = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    if (v[i].second == -1) {
      if (lastI == -1)
        increases.push_back(sumRange);
      else {
        ll cur1 = 0, best1 = 0;
        for (int j = lastI + 1, r = lastI; j < i; j++) {
          while (r + 1 < i && (v[r+1].first - v[j].first) * 2 <
                    v[i].first - v[lastI].first) {
            cur1 += v[++r].second;          
          }
          best1 = max(best1, cur1);
          cur1 -= v[j].second;
        }
        increases.push_back(best1);
        increases.push_back(sumRange - best1);
      }
      lastI = i;
      sumRange = 0;
    }
    else 
      sumRange += v[i].second;
  }
  increases.push_back(sumRange);
  sort(increases.begin(), increases.end(), [](const auto& a, const auto& b) {
    return a > b;
  });
  increases.resize(n);
  ll ans = 0;
  for (auto i : increases)
    ans += i;
  cout << ans << '\n';
}
