#include <iostream>
#include <queue>
#include <stack>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main()
{
	cin >> N;
	pair<int, int> p;
	vector<pair<int, int>> v;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p.first, &p.second);
		v.push_back(p);
	}
	int answer_size = 0;
	pair<int, int> answer_pair = { 0, 0 };
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		while (!pq.empty() && pq.top().first <= v[i].first) {
			pq.pop();
		}
		pq.push({ v[i].second, v[i].first });
		if (pq.size() == answer_size && answer_pair.second == v[i].first) {
			answer_pair.second = pq.top().first;
		}
		else if (pq.size() > answer_size) {
			answer_size = pq.size();
			answer_pair = { v[i].first, pq.top().first };
		}
	}
	printf("%d\n%d %d\n", answer_size, answer_pair.first, answer_pair.second);
	return 0;
}