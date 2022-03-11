#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  int start[100], end[100];
  cin >> N;  
  for (int i = 0; i < N; i++) {
	cin >> start[i] >> end[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
	int a[1001];
	for (int j = 0; j < 100; j++) {
	  a[j] = 0;
	}
	for (int j = 0; j < N; j++) {
	  if (i != j) {
		for (int k = start[j]; k < end[j]; k++) {
		  a[k] = 1;
		}
	  }
	}
    int cur = 0;
	for (int j = 0; j < 100; j++) {
	  if (a[j] == 1) {
		cur++;
	  }
	}
	ans = max(ans, cur);
  }
  cout << ans << "\n";
}
