#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		int ts, te;
		cin >> ts >> te;
		v.push_back({ ts,te });
		temp.push_back(ts);
		temp.push_back(te);
	}

	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	vector<int>sum(temp.size(), 0);

	for (int i = 0; i < v.size(); i++) {
		v[i].first = lower_bound(temp.begin(), temp.end(), v[i].first) - temp.begin();
		v[i].second = lower_bound(temp.begin(), temp.end(), v[i].second) - temp.begin();

		sum[v[i].first]++;
		sum[v[i].second]--;
	}

	for (int i = 1; i < sum.size(); i++) {
		sum[i] += sum[i - 1];
	}

	int maxVal = *max_element(sum.begin(), sum.end());

	auto it = find(sum.begin(), sum.end(), maxVal);
	int s = it - sum.begin();

	while (it != sum.end() && *it == maxVal) it++;
	int e = it - sum.begin();

	cout << maxVal << endl;
	cout << temp[s] << " " << temp[e] << endl;
	return 0;
}
