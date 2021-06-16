#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	int ans = 0;
	int l = -1;
	int r = 0;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)cin >> arr[i];

	for (int i = 0; i < n; i++)r += arr[i];
	r++;
	while (l + 1 < r) {
		int cnt = 0;
		int sum = 0;
		int mid = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if (sum >= mid) {
				sum = 0;
				cnt++;
			}
		}

		if (cnt >= k) {
			l = mid;
		}

		if (cnt < k) {
			r = mid;
		}

	}
	cout << l;
	return 0;
}