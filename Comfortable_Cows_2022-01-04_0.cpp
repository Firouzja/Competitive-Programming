#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int N;
int a[1001][1001];

bool comfortable(int x, int y) {
	int count = 0;
	if (a[x][y + 1] != 0) count++;
	if (a[x][y - 1] != 0) count++;
	if (a[x + 1][y] != 0) count++;
	if (a[x - 1][y] != 0) count++;
	return count == 3;
}

int main() {
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			a[i][j] = 0;
		}
	}
	vector<pair<int,int>> cows;
	cin >> N;
	while (N--) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1; 
		cows.push_back(make_pair(x, y));
		int out = 0;
		for (auto p : cows) {
			out += comfortable(p.f, p.s);
		}
		cout << out << endl; 
	}
}
