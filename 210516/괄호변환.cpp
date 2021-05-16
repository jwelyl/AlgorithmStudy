#include <string>
#include <vector>
using namespace std;

void recursive(string s, string& answer) {
	if (s == "") return;

	int cnt = 0;
	string u = "", v = "";
	int length = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt++;
		}
		else {
			cnt--;
		}

		u += s[i];

		if (cnt == 0) {
			length = i + 1;
			break;
		}
	}
	v = s.substr(length, s.size() - length);

	bool chk = true;
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(') {
			cnt++;
		}
		else {
			cnt--;
			if (cnt < 0) {
				chk = false;
				break;
			}
		}
	}

	if (chk) { //¿Ã¹Ù¸¥ °ýÈ£
		answer += u;
		recursive(v, answer);
	}
	else { //±ÕÇüÀâÈù °ýÈ£
		answer += "(";
		recursive(v, answer);
		answer += ")";
		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == '(') {
				answer += ")";
			}
			else {
				answer += "(";
			}
		}
	}

}
string solution(string p) {
	string answer = "";
	int cnt = 0;
	bool chk = true;

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			cnt++;
		}
		else {
			cnt--;
			if (cnt < 0) {
				chk = false;
				break;
			}
		}
	}
	if (chk) return p;
	recursive(p, answer);

	return answer;
}