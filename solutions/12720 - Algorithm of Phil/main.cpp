#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++) {
		string line;
		string res = "";
		int64_t result = 0;

		cin >> line;

		int mid1 = line.length() / 2;
		int mid2 = line.length() / 2 - 1;
		for (int j = 0; j < line.length(); j++) {
			result <<= 1;
			result %= 1000000007;

			if ((line.length() - j) & 1) {
				if ((int)line.length() - mid1 > mid2) {
					result += (line[mid1] == '1' ? 1 : 0);
					mid1++;
				} else {
					result += (line[mid2] == '1' ? 1 : 0);
					mid2--;
				}
			} else {
				if (line[mid2] > line[mid1]) {
					result += (line[mid2] == '1' ? 1 : 0);
					mid2--;
				} else {
					result += (line[mid1] == '1' ? 1 : 0);
					mid1++;
				}
			}

			result %= 1000000007;
		}
		cout << "Case #" << i + 1 << ": " << result << endl;
	}

	return 0;
}