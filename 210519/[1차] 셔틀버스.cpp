#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	//��Ʋ ���� Ƚ�� n, ��Ʋ ���� ���� t, �� ��Ʋ�� Ż �� �ִ� �ִ� ũ�� �� m, ũ�簡 ��⿭�� �����ϴ� �ð��� ���� �迭 timetable
	int shuttle = 540; //9�ÿ� ���
	int shuttle2 = 0;

	vector<int> time;
	for (int i = 0; i < timetable.size(); i++) {
		time.push_back(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2)));
	}
	sort(time.begin(), time.end());
	vector<bool> visit(time.size(), false);

	vector<int> time2[11];

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < time.size(); j++) {
			if (time[j] <= shuttle && !visit[j]) {
				time2[i].push_back(time[j]);
				cnt++;
				visit[j] = true;

				if (cnt == m) break;
			}
		}
		shuttle += t;
	}


	shuttle -= t;
	int h1 = 0;
	int m1 = 0;
	string hour = "";
	string minute = "";
	if (time2[n - 1].size() != m) {
		h1 = shuttle / 60;
		m1 = shuttle % 60;
		hour = to_string(h1);
		minute = to_string(m1);
		if (h1 < 10) {
			hour = "0" + to_string(h1);
		}
		if (m1 < 10) {
			minute = "0" + to_string(m1);
		}

		return hour + ":" + minute;
	}

	else {
		shuttle = time2[n - 1][time2[n - 1].size() - 1] - 1;
		h1 = shuttle / 60;
		m1 = shuttle % 60;
		hour = to_string(h1);
		minute = to_string(m1);
		if (h1 < 10) {
			hour = "0" + to_string(h1);
		}
		if (m1 < 10) {
			minute = "0" + to_string(m1);
		}

		return hour + ":" + minute;
	}

}