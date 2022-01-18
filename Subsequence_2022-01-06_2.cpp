#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int N;
	cin >> N;
	int longest_photo = 0;
	vector<int> first(7);
	for (int i = 0; i < 7; i++) {
		first[i] = -1;
	}
	first[0] = 0;
	int curr_remainder = 0;
	for (int i = 1; i <= N; i++) {
		int cow;
		cin >> cow;
		curr_remainder = (curr_remainder + cow) % 7;
		if (first[curr_remainder] == -1) {
			first[curr_remainder] = i;
		}
		else {
			longest_photo = max(longest_photo, i - first[curr_remainder]);
		}
	}
	cout << longest_photo << endl;
}
 