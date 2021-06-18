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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, e, q;
	unordered_map<string, int> m;
	cin >> s >> e >> q;
	int ss, ee, qq;
	ss = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
	ee = stoi(e.substr(0, 2)) * 60 + stoi(e.substr(3, 2));
	qq = stoi(q.substr(0, 2)) * 60 + stoi(q.substr(3, 2));
	/*
	1. 개강 총회 전까지 채팅 기록을 남김(시작까지 OK)
	2. 개총 끝나자마자 기록 or 스트리밍 끝나자마자 제시간
	*/
	while (!cin.eof()) {
		string t, n;
		cin >> t >> n;
		if (t.size() < 5) break;
		int tt = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
		if (tt <= ss && m[n] == 0) {
			m[n]++;
		}
		if (ee <= tt && tt <= qq && m[n] == 1) {
			m[n]++;
		}

	}

	int ans = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == 2)
			ans++;
	}
	cout << ans << endl;
	return 0;
}