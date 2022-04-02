#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;
int n;
int grid[MAX_N][MAX_N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
	  for (int j = 0; j < n; j++) {
	    cin >> grid[i][j];
	  }
  }
  int horizontalAnswer = 0;
  for (int i = 0; i < n; i++) {
    int sum[2]{};
    for (int j = 0; j < n; j++) {
      sum[j % 2] += grid[i][j];
    }
    horizontalAnswer += max(sum[0], sum[1]);
  } 
  int verticalAnswer = 0;
  for (int j = 0; j < n; j++) {
    int sum[2]{};
    for (int i = 0; i < n; i++) {
      sum[i % 2] += grid[i][j];
    }
    verticalAnswer += max(sum[0], sum[1]);
  }
  cout << max(verticalAnswer, horizontalAnswer) << '\n';
}