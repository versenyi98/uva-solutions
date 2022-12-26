#include <bits/stdc++.h>

using namespace std;

int main() {

	long long N, M;

	while (cin >> N >> M) {
		cout << N << ' ' << M << endl;

		vector<long long> numbers;

		for (long long i = 0; i < N; i++) {
			long long num;
			cin >> num;
			numbers.push_back(num);
		}

		sort(numbers.begin(), numbers.end(), [=] (long long a, long long b) {
			if (a % M != b % M) return a % M < b % M;
			if (abs(a % 2) != abs(b % 2)) return abs(a % 2) > abs(b % 2);
			if (a % 2 != 0) return a > b;
			return a < b;
		});

		for (auto i : numbers) {
			cout << i << endl;
		}
	}

	return 0;
}