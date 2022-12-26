#include <bits/stdc++.h>

using namespace std;

struct person {

	string name;
	int d, m, y;

	bool operator<(const person p) const {
		if (y != p.y) return y < p.y;
		if (m != p.m) return m < p.m;
		return d < p.d;
	}
};

int main() {

	int n;
	cin >> n;

	vector<person> v;

	for (int i = 0; i < n; i++) {
		person p;
		cin >> p.name >> p.d >> p.m >> p.y;
		v.push_back(p);
	}

	sort(v.begin(), v.end());
	cout << v.back().name << endl << v[0].name << endl;

	return 0;
}