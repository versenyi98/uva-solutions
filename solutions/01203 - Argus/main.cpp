#include <bits/stdc++.h>

using namespace std;

int main() {

	string line;
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
	while (cin >> line, line != "#") {
		int a, b;
		cin >> a >> b;
		pq.push({{b, a}, b});
	}

	int q;
	cin >> q;

	while (q--) {
		cout << pq.top().first.second << endl;
		pq.push({{pq.top().first.first + pq.top().second, pq.top().first.second}, pq.top().second});
		pq.pop();
	}

	return 0;
}