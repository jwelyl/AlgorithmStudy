#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> m;

	for (int i = 0; i < record.size(); i++) {
		string id = "";
		string name = "";
		int cnt = 0;
		for (int j = 0; j <= record[i].size(); j++) {
			if (record[i].at(0) == 'E' || record[i].at(0) == 'C') {
				if (j == record[i].size()) {
					m[name] = id;
					break;
				}
				if (record[i].at(j) == ' ') {
					if (cnt == 1) {
						m[id];
						name = id;
					}
					cnt++;
					id = "";
				}
				else {
					id += record[i].at(j);
				}
			}
			else {
				break;
			}
		}
	} //map에다가 저장

	//uid1234 = prodo
	//uid4567 = ryan

	for (int i = 0; i < record.size(); i++) {
		string id = "";
		int cnt = 0;
		string name = "";
		for (int j = 0; j < record[i].size(); j++) {
			if (record[i].at(0) == 'E') {
				if (record[i].at(j) == ' ') {
					if (cnt == 1) {
						name = m[id];
						answer.push_back(name + "님이 들어왔습니다.");
						break;
					}
					cnt++;
					id = "";
				}
				else {
					id += record[i].at(j);
				}
			}

			else if (record[i].at(0) == 'L') {
				if (record[i].at(j) == ' ') {
					if (cnt == 1) {

						break;
					}
					cnt++;
					id = "";
				}
				else {
					id += record[i].at(j);
				}

				if (record[i].size() - 1 == j) {
					name = m[id];
					answer.push_back(name + "님이 나갔습니다.");
				}
			}
		}
	}

	return answer;
}