#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

void count_freq(const string &s, array<int, 26> &freq) {
	for (char c : s) {
		freq[c - 'a']++;
	}
}

int main() {
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	int n;
	cin >> n;
	array<int, 26> ans{};
	while (n--) {
		string s1, s2;
		cin >> s1 >> s2;
		array<int, 26> freq1{}, freq2{};
		count_freq(s1, freq1); count_freq(s2, freq2);
		for (int i = 0; i < 26; i++) {
			ans[i] += max(freq1[i], freq2[i]);
		}
	}
	for (int i : ans) {
		cout << i << endl;
	}
	return 0;
}
