#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int N, K;
pair<int,int> A, B;
vector<int> original, cur;

vector<int> apply(vector<int> v) {
	reverse(v.begin() + A.f, v.begin() + A.s + 1);
	reverse(v.begin() + B.f, v.begin() + B.s + 1);
	return v;
}

int main() {
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	cin >> N >> K >> A.f >> A.s >> B.f >> B.s;
	A.f--; A.s--; B.f--; B.s--;
	
	original.resize(N);
	
	iota(begin(original), end(original), 0);


	cur = original;
	int period = 0;
	
	do {
		period++;
		cur = apply(cur);
	} while (cur != original);

	for (K %= period; K; K--) {
		cur = apply(cur);
	}
	
	for (int t : cur) cout << t + 1 << endl;
}
