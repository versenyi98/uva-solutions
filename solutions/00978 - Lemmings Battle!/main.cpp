#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	for (int tc = 0; tc < test_cases; tc++) {
		int bf, sg, sb;

		multiset<int, greater<int>> green_army, blue_army;
		vector<int> green_survivors, blue_survivors;

		cin >> bf >> sg >> sb;

		int lemming;
		for (int i = 0; i < sg; i++) {
			cin >> lemming;
			green_army.insert(lemming);
		}

		for (int i = 0; i < sb; i++) {
			cin >> lemming;
			blue_army.insert(lemming);
		}

		while (blue_army.size() && green_army.size()) {

			for (int i = 0; i < bf; i++) {
				if (blue_army.size() && green_army.size()) {
					int blue = *blue_army.begin();
					int green = *green_army.begin();

					blue_army.erase(blue_army.begin());
					green_army.erase(green_army.begin());

					if (blue > green) {
						blue_survivors.push_back(blue - green);
					} else if (green > blue) {
						green_survivors.push_back(green - blue);
					}
				}
			}
			for (auto b : blue_survivors) blue_army.insert(b);
			for (auto g : green_survivors) green_army.insert(g);

			blue_survivors.clear();
			green_survivors.clear();
		}
		if (tc) cout << endl;
		if (!blue_army.size() && !green_army.size()) {
			cout << "green and blue died" << endl;
		}
		if (blue_army.size()) {
			cout << "blue wins" << endl;
			for (auto b : blue_army) cout << b << endl;
		}
		if (green_army.size()) {
			cout << "green wins" << endl;
			for (auto g : green_army) cout << g << endl;
		}
	}

	return 0;
}