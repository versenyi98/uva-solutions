#include <bits/stdc++.h>

using namespace std;

struct data {

	string title, first_name, last_name, dep, home, work, campus, place;

	bool operator<(const data d) const {
		return last_name < d.last_name;
	}

};

int main() {

	int n;
	cin >> n;

	vector<data> v;

	string trash;
	getline(cin, trash);

	while (n--) {
		string dep;
		getline(cin, dep);

		string line;
		while (getline(cin, line) && line.length()) {
			data d;

			auto pos = line.find(',');
			d.title = line.substr(0, pos);
			line = line.substr(pos + 1);

			pos = line.find(',');
			d.first_name = line.substr(0, pos);
			line = line.substr(pos + 1);

			pos = line.find(',');
			d.last_name = line.substr(0, pos);
			line = line.substr(pos + 1);

			pos = line.find(',');
			d.place = line.substr(0, pos);
			line = line.substr(pos + 1);

			pos = line.find(',');
			d.home = line.substr(0, pos);
			line = line.substr(pos + 1);

			pos = line.find(',');
			d.work = line.substr(0, pos);
			line = line.substr(pos + 1);

			d.campus = line;

			d.dep = dep;

			v.push_back(d);
		}
	}

	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << "----------------------------------------" << endl;
		cout << i.title << ' ' << i.first_name << ' ' << i.last_name << endl;
		cout << i.place << endl;
		cout << "Department: " << i.dep << endl;
		cout << "Home Phone: " << i.home << endl;
		cout << "Work Phone: " << i.work << endl;
		cout << "Campus Box: " << i.campus << endl;
	}
	return 0;
}