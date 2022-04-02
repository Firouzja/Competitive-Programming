#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2501;
int n;
int arr[MAX_N];
vector<int> adj[MAX_N];
int sum0, sum1, nodes0, nodes1;

void dfs(int node, int color, int prev) {
  if (color == 0) {
    nodes0++;
    sum0 += arr[node];
  }
  else {
    nodes1++;
    sum1 += arr[node];
  }
  for (int u : adj[node]) {
    if (u != prev) {
      dfs(u, 1 - color, node);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b; a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, 0, -1);
  if (sum0 % 12 == sum1 % 12)
    cout << n << '\n';
  else if ((sum0 + 1) % 12 == sum1 % 12)
    cout << nodes1 << '\n';
  else if (sum0 % 12 == (sum1 + 1) % 12)
    cout << nodes0 << '\n';
  else  
    cout << "0\n";
}