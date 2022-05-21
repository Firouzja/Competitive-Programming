#include <bits/stdc++.h>

using namespace std;
 
const int MAX_N = 2e5+10;
 
int val[MAX_N];
int cap[MAX_N];
int par[MAX_N];
int pla[MAX_N];
 
int N, Q;
 
int get(int x) {
  return par[x] == x ? x : par[x] = get(par[x]);
}
 
void unite(int a, int b) {
  a = get(a);
  b = get(b);
  par[a] = b;
  pla[b] = max(pla[a], pla[b]);
}
 
void upd(int x, int i) {
  i = pla[get(i)];
  if (i > N || x == 0) return;
  val[i] += x;
  if (val[i] > cap[i]) {
    int tmp = val[i] - cap[i];
    val[i] = cap[i];
    unite(i, i + 1);
    upd(tmp, i);
  }
}
 
int main() {
  cin >> N;
  for(int i = 1; i <= N; ++i) {
    cin >> cap[i];
    par[i] = pla[i] = i;
  }
  par[N + 1] = pla[N + 1] = N + 1;
  cin >> Q;
  for(int i = 0; i < Q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      upd(x, p);
    } else if (t == 2) {
      int k;
      cin >> k;
      cout << val[k] << "\n";
    }
  }
  return 0;
}
