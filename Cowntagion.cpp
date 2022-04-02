#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
vector<int> adj[MAXN];

int dfs(int start, int parent) {
	int ans = 0;
	int cows = adj[start].size();
	if (parent == -1) {
		cows++;
	}

	int currCows = 1;
	int days = 0;
	while (currCows < cows) {
		days++;
		currCows *= 2;
	}
	ans += days;

	for (auto next : adj[start]) {
		if (next != parent) {
			ans += dfs(next, start) + 1;
		}
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a,b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << dfs(0, -1) << endl;
	return 0;
}