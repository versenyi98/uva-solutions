#include <bits/stdc++.h>

using namespace std;

int main() {

	int test_cases;
	cin >> test_cases;
	string title;
	for (int t = 0; t < test_cases; t++) {
		getline(cin, title); getline(cin, title);

		int m, n, b;
		cin >> m >> n >> b;

		unordered_map<string, int> ingredient_price;
		for (int i = 0; i < m; i++) {
			string ingredient;
			int price;
			cin >> ingredient >> price;
			ingredient_price[ingredient] = price;
		}

		auto comp = [](pair<int, string> a, pair<int, string> b) {
			if (a.first == b.first) {
				return a.second < b.second;
			}
			return a.first < b.first;
		};

		set<pair<int, string>, decltype(comp)> s(comp);

		for (auto c : title) putchar(toupper(c));
		cout << endl;
		for (int i = 0; i < n; i++) {
			string name;
			getline(cin, name); getline(cin, name);
			int nn;
			int current_price = 0;
			cin >> nn;

			for (int j = 0; j < nn; j++) {
				string ing;
				int amount;
				cin >> ing >> amount;

				current_price += (amount * ingredient_price[ing]);
			}

			if (current_price <= b) s.insert({current_price, name});
		}

		if (s.size() == 0) {
			cout << "Too expensive!" << endl;
		} else {
			for (auto i : s) {
				cout << i.second << endl;
			}
		}
		cout << endl;
	}

	return 0;
}