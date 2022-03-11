#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int,int>> tasks(n);
  for (auto& task : tasks) 
	cin >> task.first >> task.second;
  sort(tasks.begin(), tasks.end());
  int time = 0, ans = 0;
  for (auto task : tasks) {
	time += task.first;
	ans += task.second - time;
  }
  cout << ans << "\n";
}

// sort tasks by duration