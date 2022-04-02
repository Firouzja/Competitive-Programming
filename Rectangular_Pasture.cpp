#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

bool cmp(pair<int,int> a, pair<int,int> b) {
  return a.second < b.second;
}

const int MAX_N = 2500 + 1;
int n;
int pSum[MAX_N][MAX_N];
vector<pair<int,int>> p;

int rSum(int x1, int y1, int x2, int y2) {
  return pSum[x2+1][y2+1] - pSum[x2+1][y1] - pSum[x1][y2+1] + pSum[x1][y1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  sort(all(p));
  for (int i = 0; i < n; i++) p[i].first = i + 1;
  sort(all(p), cmp);
  for (int i = 0; i < n; i++) p[i].second = i + 1;
  for (int i = 0; i < n; i++) pSum[p[i].first][p[i].second] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pSum[i][j] += pSum[i-1][j] + pSum[i][j-1] - pSum[i-1][j-1];
    }
  }  
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int x1 = min(p[i].first, p[j].first) - 1;
      int x2 = max(p[i].first, p[j].first) - 1;
      ans += rSum(0, i, x1, j) * rSum(x2, i, n-1, j);
    }
  }
  cout << ans + 1 << '\n';
}