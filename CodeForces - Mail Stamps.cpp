#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+1;

int u[MAX_N];
int v[MAX_N];
map<int,int> A, B;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> u[i] >> v[i]; 
    if (!A[u[i]]) A[u[i]] = v[i]; else B[u[i]] = v[i]; 
    if (!A[v[i]]) A[v[i]] = u[i]; else B[v[i]] = u[i];
  }
  int node = 0, prv = 0;
  for (int i = 0; i < n; i++) {
    for (int j : {u[i], v[i]}) {
      if (!B[j]) {
        node = j;
        break;
      }
    }
  }
  cout << node;
  for (int i = 0; i < n; i++) {
    int nxt = 0;
    if (A[node] != prv) 
      nxt = A[node];
    else  
      nxt = B[node];
    prv = node;
    node = nxt;
    cout << ' ' << node;
  }
  return 0;
}
