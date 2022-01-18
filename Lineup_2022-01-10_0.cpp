#include <bits/stdc++.h>
using namespace std;

vector<string> cows, A, B;
string a, b, t;
int N;


int where(string c) {
	for (int i = 0; i < 8; i++) {
		if (cows[i] == c) return i;
	}
	return -1;
}

bool good() {
	for (int i = 0; i < N; i++) {
		if (abs(where(A[i]) - where(B[i])) != 1) return false;
	}
	return true;
}

int main() {
	cows.push_back("Beatrice");
	cows.push_back("Belinda");
	cows.push_back("Bella");
	cows.push_back("Bessie");
	cows.push_back("Betsy");
	cows.push_back("Blue");
	cows.push_back("Buttercup");
	cows.push_back("Sue");

	cin >> N;

	while (N--) {
		cin >> a; 
		cin >> t; // must
		cin >> t; // be
		cin >> t; // milked
		cin >> t; // beside
		cin >> b; 
		A.push_back(a);
		B.push_back(b);
	}

	do {
		if (good()) {
			for (int i = 0; i < 8; i++) {
				cout << cows[i] << endl;
			}
			break;
		}
	} while(next_permutation(cows.begin(), cows.end()));
}
