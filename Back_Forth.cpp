#include <bits/stdc++.h>
using namespace std;

set<int> perms;

void friday(int total, vector<int> b) {
  for (int i = 0; i < (int)b.size(); i++) {
	perms.insert(total + b[i]);
  }
}

void thursday(int total, vector<int> a, vector<int> b) {
  for (int i = 0; i < (int)a.size(); i++) {
	vector<int> newB = b; newB.push_back(a[i]);
	vector<int> newA = a; newA.erase(newA.begin() + i);
	friday(total - a[i], newB);
  }
}

void wednesday(int total, vector<int> b, vector<int> a) {
  for (int i = 0; i < (int)a.size(); i++) {
	vector<int> newB = b; newB.push_back(a[i]);
	vector<int> newA = a; newA.erase(newA.begin() + i);
	thursday(total + a[i], newA, newB);
  }
}

void tuesday(int total, vector<int> a, vector<int> b) {
  for (int i = 0; i < (int)a.size(); i++) {
	vector<int> newB = b; newB.push_back(a[i]);
	vector<int> newA = a; newA.erase(newA.begin() + i);
	wednesday(total - a[i], newA, newB);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  vector<int> a, b;
  for (int i = 0; i < 10; i++) {
	int x;
	cin >> x;
	a.push_back(x);
  }
  for (int i = 0; i < 10; i++) {
	int x;
	cin >> x;
	b.push_back(x);
  }
  tuesday(1000, a, b);
  cout << perms.size() << "\n";
}
