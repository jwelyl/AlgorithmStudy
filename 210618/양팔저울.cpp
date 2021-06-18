#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
#include<cmath>
using namespace std;
vector<int> v;
vector<int> sum;
bool visit[14] = { false };
vector<char> sign;
set<int> Set;

void dfs(int start, int size) {

	if (sum.size() == size) {
		int num = sum[0];

		for (int i = 0; i < sign.size(); i++) {
			if (sign[i] == '+') {
				num += sum[i + 1];
			}
			else {
				num -= sum[i + 1];
				num = abs(num);
			}
		}
		Set.insert(num);
		return;
	}

	for (int i = start; i < v.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			sum.push_back(v[i]);

			if (sum.size() != 1) {
				for (int j = 0; j < 2; j++) {
					if (j == 0) {
						sign.push_back('+');
					}
					else {
						sign.push_back('-');
					}
					dfs(i + 1, size);
					sign.pop_back();
				}

			}
			else {
				dfs(i + 1, size);
			}

			sum.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	v = vector<int>(n);

	int num = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		num += v[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(0, i);
	}
	int ans = 0;
	for (int i = 1; i <= num; i++) {
		auto iter = Set.find(i);
		if (iter == Set.end()) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}