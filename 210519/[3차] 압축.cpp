#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;

	vector<string> list(27);
	for (int i = 0; i < 26; i++) {
		list[i + 1] = 'A' + i;
	}

	int idx = 0;
	string w = "";
	string c = "";
	while (idx < msg.size()) {
		bool chk = true;

		while (1) {
			w += msg[idx];
			c = msg[idx + 1];

			auto it = find(list.begin(), list.end(), w + c);

			if (it == list.end() && c != "") { //¾ø´Ù¸é
				it = find(list.begin(), list.end(), w);
				int location = distance(list.begin(), it);
				if (chk) {
					answer.push_back(location);
				}
				else
				{
					answer.push_back(location);
				}
				list.push_back(w + c);
				break;
			}
			else {
				chk = false;
				idx++;
			}

		}

		w = "";
		idx++;
	}
	return answer;
}