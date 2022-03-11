#include <bits/stdc++.h>
using namespace std;
 
const int MN = 1e6 + 1;
int N, M, answer = 0;
int L[MN];
vector<int> S[MN], D[MN];
bool impossible = 0;
 
void dfs(int x, int v) {
  L[x] = v;
  for (auto n : S[x]) {
    if (L[n] == 3-v) impossible = true; 
    if (L[n] == 0) dfs(n, v);
  }
  for (auto n : D[x]) {
    if (L[n] == v) impossible = true; 
    if (L[n] == 0) dfs(n, 3-v);
  }  
}
 
int main(void) {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    char c;
    cin >> c >> a >> b;
    if (c == 'S') { S[a].push_back(b); S[b].push_back(a); }
    if (c == 'D') { D[a].push_back(b); D[b].push_back(a); }
  }
  for (int i = 1; i <= N; i++) {
    if (!L[i]) { 
	  dfs(i,1); 
	  answer++; 
	}
  }
  if (impossible) cout << "0\n";
  else {
    cout << "1";
    for (int i = 0; i < answer; i++) cout << "0";
    cout << "\n";
  }
}