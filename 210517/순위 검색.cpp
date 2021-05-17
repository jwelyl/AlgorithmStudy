#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int find(string s) {
	if (s == "cpp") return 1;
	else if (s == "java") return 2;
	else if (s == "python") return 3;
	else if (s == "backend") return 1;
	else if (s == "frontend") return 2;
	else if (s == "junior") return 1;
	else if (s == "senior") return 2;
	else if (s == "chicken") return 1;
	else if (s == "pizza") return 2;
	else if (s == "-") return 0;
}

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		if (temp != "and")
			answer.push_back(temp);
	}

	return answer;
}
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	vector<int> data[4][3][3][3];
	int score = 0;
	string temp = "";
	for (int i = 0; i < info.size(); i++) {
		vector<int> in;
		for (int j = 0; j <= info[i].size(); j++) {

			if (j == info[i].size()) {
				score = stoi(temp);
				temp = "";
				break;
			}
			if (info[i].at(j) == ' ') {
				in.push_back(find(temp));
				temp = "";
			}
			else {
				temp += info[i].at(j);
			}
		}
		data[0][0][0][0].push_back(score);
		data[in[0]][0][0][0].push_back(score);
		data[0][in[1]][0][0].push_back(score);
		data[0][0][in[2]][0].push_back(score);
		data[0][0][0][in[3]].push_back(score);

		data[in[0]][in[1]][0][0].push_back(score);
		data[in[0]][0][in[2]][0].push_back(score);
		data[in[0]][0][0][in[3]].push_back(score);
		data[0][in[1]][in[2]][0].push_back(score);
		data[0][in[1]][0][in[3]].push_back(score);
		data[0][0][in[2]][in[3]].push_back(score);

		data[in[0]][in[1]][in[2]][0].push_back(score);
		data[in[0]][in[1]][0][in[3]].push_back(score);
		data[in[0]][0][in[2]][in[3]].push_back(score);
		data[0][in[1]][in[2]][in[3]].push_back(score);

		data[in[0]][in[1]][in[2]][in[3]].push_back(score);
	}

	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 3; b++) {
			for (int c = 0; c < 3; c++) {
				for (int d = 0; d < 3; d++) {
					sort(data[a][b][c][d].begin(), data[a][b][c][d].end());
				}
			}
		}
	}

	for (int i = 0; i < query.size(); i++) {
		vector<string> q;
		q = split(query[i], ' ');
		int find_score = stoi(q[4]);
		vector<int> in;
		int cnt = 0;
		for (int j = 0; j < q.size(); j++) {
			in.push_back(find(q[j]));
		}
		int length = data[in[0]][in[1]][in[2]][in[3]].size();

		cnt = lower_bound(data[in[0]][in[1]][in[2]][in[3]].begin(),
			data[in[0]][in[1]][in[2]][in[3]].end(), find_score) - data[in[0]][in[1]][in[2]][in[3]].begin();

		answer.push_back(length - cnt);
	}
	return answer;
}