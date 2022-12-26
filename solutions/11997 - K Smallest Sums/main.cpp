#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int k;

	while (cin >> k) {

		int result[k];
		int temp[k];

		for (int i = 0; i < k; i++) cin >> result[i];
		sort(result, result + k);

		for (int i = 1; i < k; i++) {
			for (int j = 0; j < k; j++) cin >> temp[j];
			sort(temp, temp + k);

			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

			for (int j = 0; j < k; j++) {
				pq.push({result[j] + temp[0], 1});
			}
			
			for (int j = 0; j < k; j++) {
				auto top = pq.top();
				pq.pop();

				result[j] = top.first;
				if (top.second != k) {
					pq.push({top.first - temp[top.second - 1] + temp[top.second], top.second + 1});
				}
			}
		}

		for (int i = 0; i < k; i++) {
			if (i) printf(" ");
			printf("%d", result[i]);
		}

		printf("\n");
	}

	return 0;
}