#include <iostream>
#include <queue>
using namespace std;

bool visited[200000]{};
int destinations[200000];
int pathlength[200000]{};
queue<int> path;
int steps = 0;

void dfs(int planet) {
	path.push(planet);
	if (visited[planet]){
		steps += pathlength[planet];
		return;
	}
	visited[planet] = true;
	steps++;
	dfs(destinations[planet]);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> destinations[i];
		destinations[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			steps = 0;
			dfs(i);
			int decrement = 1;
			while (!path.empty()) {
				if (path.front() == path.back()) {
					decrement = 0;
				}
				pathlength[path.front()] = steps;
				steps -= decrement;
				path.pop();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << pathlength[i] << " ";
	}
	cout << '\n';
}