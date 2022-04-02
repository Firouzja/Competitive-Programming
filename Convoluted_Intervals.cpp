#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> ivals(N);
	for (auto &i : ivals)
		cin >> i.first >> i.second;
	vector<int64_t> win_start(2 * M + 1), win_end(2 * M + 1);
	{
		vector<int64_t> a_freq(M + 1);
		for (int i = 0; i < N; ++i)
			++a_freq.at(ivals.at(i).first);
		for (int i = 0; i <= M; ++i)
			for (int j = 0; j <= M; ++j)
				win_start.at(i + j) += a_freq.at(i) * a_freq.at(j);
	}
	{
		vector<int64_t> b_freq(M + 1);
		for (int i = 0; i < N; ++i)
			++b_freq.at(ivals.at(i).second);
		for (int i = 0; i <= M; ++i)
			for (int j = 0; j <= M; ++j)
				win_end.at(i + j) += b_freq.at(i) * b_freq.at(j);
	}
	int64_t win_count = 0;
	for (int i = 0; i <= 2 * M; ++i) {
		win_count += win_start.at(i);
		cout << win_count << '\n';
		win_count -= win_end.at(i);
	}
}