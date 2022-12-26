#include <bits/stdc++.h>

using namespace std;

struct record {
	string plate = "";
	int month = -1;
	int day = -1;
	int hour = -1;
	int minute = -1;
	string operation = "";
	int km = -1;

	bool operator>(const record& rec) const {
		if (month != rec.month) return month > rec.month;
		if (day != rec.day) return day > rec.day;
		if (hour != rec.hour) return hour > rec.hour;
		if (minute != rec.minute) return minute > rec.minute;
	}
};

int main() {

	ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;
	string line;

	for (int tt = 0; tt < test_cases; tt++) {

		map<string, priority_queue<record, vector<record>, greater<record>>> m_pq;
		map<string, int> cost;
		map<string, bool> valid;

		if (tt) cout << endl;

		int price[24];
		for (int i = 0; i < 24; i++) {
			cin >> price[i];
		}

		getline(cin, line);

		while (getline(cin, line) && line.length()) {
			stringstream ss;
			ss << line;
			record r;
			char sep;
			ss >> r.plate >> r.month >> sep >> r.day >> sep >> r.hour >> sep >> r.minute >> r.operation >> r.km;

			m_pq[r.plate].push(r);
		}

		for (auto i : m_pq) {
			record last_record;
			while (i.second.size()) {
				auto top = i.second.top();
				i.second.pop();

				if (last_record.operation == "enter" && top.operation == "exit") {
					cost[i.first] += abs(top.km - last_record.km) * price[last_record.hour] + 100;
					valid[i.first] = true;
				}
				last_record = top;
			}

			if (valid[i.first]) {
				printf("%s $%.2f\n", i.first.c_str(), 2 + (double)(cost[i.first]) / 100.0);
			}
		}
	}

	return 0;
}