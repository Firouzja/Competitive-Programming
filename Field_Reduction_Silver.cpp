#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int INF = 1e6;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int,int>> x, y;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    x.push_back(make_pair(a, i));
    y.push_back(make_pair(b, i));
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  for (auto i : x) cout << i.f << ' ';
  cout << '\n';
  for (auto i : y) cout << i.f << ' ';
  cout << '\n';
  int ans = INF;
  for (int ix = 0; ix < 4; ix++) { 
    for (int jx = 0; jx < 4 - ix; jx++) { 
      for (int iy = 0; iy < 4 - ix - jx; iy++) { 
        for (int jy = 0; jy < 4 - ix - iy - jx; jy++) { 
          set<int> ixTaken, jxTaken, iyTaken, jyTaken;
          for (int kx = 0; kx < ix; kx++) {
            for (int ky = 0; ky < iy; ky++) {
              if (x[kx].s == y[ky].s) {
                ixTaken.insert(ky);
                iyTaken.insert(kx);
              }
            }
          }
          for (int kx = 0; kx < ix; kx++) {
            for (int ky = 0; ky < jy; ky++) {
              if (x[kx].s == y[n-ky-1].s) {
                ixTaken.insert(ky);
                jyTaken.insert(kx);
              }
            }
          }
          for (int kx = 0; kx < jx; kx++) {
            for (int ky = 0; ky < iy; ky++) {
              if (x[n-kx-1].s == y[ky].s) {
                jxTaken.insert(ky);
                iyTaken.insert(kx);
              }
            }
          }
          for (int kx = 0; kx < jx; kx++) {
            for (int ky = 0; ky < jy; ky++) {
              if (x[n-kx-1].s == y[n-ky-1].s) {
                jxTaken.insert(ky);
                jyTaken.insert(kx);
              }
            }
          }
          int xDist = x[n-jx-1-(int)jxTaken.size()].f - x[ix+(int)ixTaken.size()].f;
          int yDist = y[n-jy-1-(int)jyTaken.size()].f - y[iy+(int)iyTaken.size()].f;
          if (!(xDist == 9 && yDist == 5)) continue;
          cout << jx << ' ' << ix << ' ' << jy << ' ' << iy << '\n';
          cout << x[n-jx-1].f << ' ' << x[ix].f;
          cout << y[n-jy-1].f << ' ' << y[iy].f;
          cout << xDist << ' ' << yDist << '\n';
          cout << ixTaken.size() << ' ' << jxTaken.size() << ' '  
                                        << iyTaken.size() << ' ' 
                                        << jyTaken.size() << '\n';
          ans = min(ans, xDist*yDist);
        }
      }
    }
  }
  cout << ans << '\n';
}